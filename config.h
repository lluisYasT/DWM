/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

#define NUMCOLORS 4
#define MODKEY Mod4Mask
// #define MONKEY Mod4Mask
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* appearance */
static const char font[]            = "Ubuntu Mono:size=9:antialias=true:hinting=true"; /*:rgba=rgb:hintstyle=hintsfull:lcdfilter=lcdlight:dpi=96";*/
static const char wallpaper[]       = "/home/lluis/.share/wallpaper.jpg";
static const char colors[NUMCOLORS][ColLast][9] = {
    /* border   foreground  background */
    { "#93a1a1", "#93a1a1", "#FFFFFF" },
    { "#073642", "#073642", "#FFFFFF" },
    { "#CB4B16", "#Cb4B16", "#FFFFFF" },
    { "#16596A", "#93a1a1", "#FFFFFF" },
};

/* settings */
static const unsigned int borderpx       = 1;      /* Border pixel of windows */
static const unsigned int snap           = 2;      /* Snap pixel */
static const unsigned int minwsz         = 20;     /* Minimal heigt of a client for smfact */
static const float mfact                 = 0.63;   /* factor of master area size [0.05..0.95] */
static const float smfact                = 0.00;   /* factor of tiled clients [0.05..1.00] */
static const char chatclient[]           = "jente_etnej - Skype™"; /* Name of chat client for chatlayout */
static const char clock_fmt[]            = "%a %d %b, %R";         /* Clock format on the bar */
static const char clsymbol[]             = "×";    /* Symbol for close button */
static const int nmaster                 = 1;      /* number of clients in master area */
static const Bool showbar                = True;   /* False means no bar */
static const Bool topbar                 = True;   /* False means bottom bar */
static const Bool resizehints            = False;  /* True means respect size hints in tiled resizals */

/* layouts */
static const Layout layouts[] = {
  /* symbol arrange */
	{ " T",  tile },
	{ " C",  chat },
	{ " B",  bstack },
	{ " M",  monocle },
	{ " F",  NULL },
};

/* tagging */
static const Tag tags[] = {
	/* name		 layout       mfact	nmaster */
	{ "1:web",	&layouts[0], -1,	-1 },
	{ "2:chill", 	&layouts[1], 0.80,	-1 },
	{ "3:term",	&layouts[0], -1,	-1 },
	{ "4:media", 	&layouts[3], -1,	-1 },
	{ "5:work",	&layouts[3], -1,	-1 },
};

/* rules */
static const Rule rules[] = {
    /*WM_CLASS              WM_CLASS    WM_NAME
	class                 instance    title               tags mask   isfloating  monitor */
	{ "Chrome",            NULL,       NULL,               1,          False,      -1 },
	{ "MPlayer",            NULL,       NULL,               1 << 3,     True,       -1 },
	{ "Gimp",               NULL,       NULL,               1 << 3,     False,      -1 },
	{ "Darktable",               NULL,       NULL,               1 << 3,     False,      -1 },
	{ "Eog",                NULL,       NULL,               1 << 3,     False,      -1 },
	{ "VirtualBox",         NULL,       NULL,               1 << 3,     False,      -1 },
	{ "Evince",             NULL,       NULL,               1 << 4,     False,      -1 },
	{ "libreoffice-writer", NULL,       NULL,               1 << 4,     False,      -1 },
	{ "libreoffice-startcenter", NULL,  NULL,               1 << 4,     False,      -1 },
	{ "subl",              	NULL,       NULL,               1 << 4,     False,      -1 },
};

/* commands */
static const char *dmenu[]   = { "dmenu_run", "-f", "-p", "Run:", NULL };
static const char *find[]    = { "dmenu_finder", NULL };
static const char *dmfm[]    = { "dmenu_fm", NULL };
static const char *term[]    = { "st", "-e", "tmux",NULL };
static const char *browser[] = { "google-chrome", NULL };
static const char *files[]   = { "st", "-e", "ranger", NULL };
static const char *music[]   = { "audacious", NULL };
static const char *skype[]   = { "skype", NULL };
static const char *scrot[]   = { "gnome-screenshot", NULL };
static const char *kill[]    = { "xkill", NULL };
static const char *lock[]    = { "i3lock", "-c", "000000", NULL };
static const char *halt[]    = { "dmenu_shutdown", NULL };
static const char *volup[]   = { "amixer", "-q", "sset", "Master", "5%+", "unmute", NULL };
static const char *voldown[] = { "amixer", "-q", "sset", "Master", "5%-", "unmute", NULL };
static const char *volmute[] = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *play[]    = { "audtool", "playback-playpause", NULL };
static const char *next[]    = { "audtool", "playlist-advance", NULL };
static const char *prev[]    = { "audtool", "playlist-reverse", NULL };
static const char *stop[]    = { "audtool", "playback-stop", NULL };
static const char *subl[]	 = { "subl", NULL};

/* shortcuts */
static Key keys[] = {
	/* modifier                 key        function        argument */
	{ MODKEY,                   XK_r,                       spawn,          {.v = dmenu } },
	{ MODKEY,                   XK_x,                       spawn,          {.v = kill } },
	{ MODKEY|ControlMask,       XK_l,                       spawn,          {.v = lock } },
	{ MODKEY,                   XK_Escape,                  spawn,          {.v = halt } },
	{ MODKEY,                   XK_z,                       spawn,          {.v = find } },
	{ MODKEY,                   XK_o,                       spawn,          {.v = dmfm } },
	{ MODKEY,                   XK_1,                       spawn,          {.v = term } },
	{ MODKEY,                   XK_2,                       spawn,          {.v = browser } },
	{ MODKEY,                   XK_3,                       spawn,          {.v = files } },
	{ MODKEY,                   XK_4,                       spawn,          {.v = music } },
	{ MODKEY,                   XK_5,                       spawn,          {.v = subl } },
	{ MODKEY|ControlMask,       XK_b,                       togglebar,      {0} },
	{ MODKEY|ControlMask,       XK_q,                       quit,           {0} },
	{ MODKEY,                   XK_j,                       focusstack,     {.i = +1 } },
	{ MODKEY,	            XK_k,                       focusstack,     {.i = -1 } },
	{ MODKEY,                   XK_Return,                  zoom,           {0} },
	{ MODKEY|ControlMask,       XK_Tab,                     view,           {0} },
	{ MODKEY,                   XK_q,                       killclient,     {0} },
	{ MODKEY,                   XK_h,                       setmfact,       {.f = -0.05} },
	{ MODKEY,                   XK_l,                 	setmfact,       {.f = +0.05} },
	{ MODKEY,                   XK_0,                       setsmfact,      {.f = +0.05} },
	{ MODKEY,                   XK_p,                       setsmfact,      {.f = -0.05} },
	{ MODKEY,                   XK_plus,                    incnmaster,     {.i = +1 } },
	{ MODKEY,                   XK_ccedilla,                 incnmaster,     {.i = -1 } },
	{ MODKEY,                   XK_space,                   setlayout,      {0} },
	{ MODKEY,                   XK_Up,                      pushup,         {0} },
	{ MODKEY,                   XK_Down,                    pushdown,       {0} },
	{ MODKEY,                   XK_Left,                    cycle,          {.i = -1 } },
	{ MODKEY,                   XK_Right,                   cycle,          {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_Left,                    tagcycle,       {.i = -1 } },
	{ MODKEY|ShiftMask,         XK_Right,                   tagcycle,       {.i = +1 } },
	{ MODKEY|ShiftMask,         XK_f,                       togglefloating, {0} },
	{ MODKEY,                   XK_t,                       setlayout,      {.v = &layouts[0] } },
	{ MODKEY,                   XK_c,                       setlayout,      {.v = &layouts[1] } },
	{ MODKEY,                   XK_b,                       setlayout,      {.v = &layouts[2] } },
	{ MODKEY,                   XK_m,                       setlayout,      {.v = &layouts[3] } },
	{ MODKEY,                   XK_f,                       setlayout,      {.v = &layouts[4] } },
	TAGKEYS(                    XK_F1,                      0)
	TAGKEYS(                    XK_F2,                      1)
	TAGKEYS(                    XK_F3,                      2)
	TAGKEYS(                    XK_F4,                      3)
	TAGKEYS(                    XK_F5,                      4)
	{ MODKEY,                   XK_a,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,         XK_a,                       tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,                   XK_Left,                    focusmon,       {.i = -1 } },
	{ MODKEY|ControlMask,                   XK_Right,                   focusmon,       {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,         XK_Left,                    tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask,         XK_Right,                   tagmon,         {.i = +1 } },
};

/* mouse button */
/* click can be ClkLtSymbol, ClkStatusText, ClkClock, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkClSymbol,          0,              Button1,        killclient,     {0} },
	/*{ ClkClock,             0,              Button1,        killclient,     {0} },*/
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        tag,            {0} },
};

