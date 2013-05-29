pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
groups=(custom)
license=('MIT')
depends=('libx11')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=("http://dl.suckless.org/$pkgname/$pkgname-$pkgver.tar.gz"
         'config.h'
         'buildflags.diff'
        )
_patches=(
          00-dwm-6.0-pertag2.diff
          01-dwm-6.0-xft.diff
          02-dwm-6.0-statuscolors.diff
          03-dwm-6.0-hideempty.diff
          04-dwm-6.0-chat.diff
          05-dwm-6.0-push.diff
          06-dwm-6.0-cycle.diff
          07-dwm-6.0-occupiedcol.diff
          08-dwm-6.0-singularborders.diff
          09-dwm-6.0-attachaside.diff
          10-dwm-6.0-centerclock.diff
          11-dwm-6.0-monocleindicator.diff
          12-dwm-6.0-focusfollowmousetag.diff
          13-dwm-6.0-removeunfunc.diff
          14-dwm-6.0-xkeycodetokeysymfix.diff
          15-dwm-6.0-smfact.diff
          16-dwm-6.0-netwmdemandsattention.diff
          17-dwm-6.0-closesymbol.diff
          18-dwm-6.0-zoomswap.diff
		 )
source=(${_source[@]} ${_patches[@]})

build() {
  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h .

  patch -Np1 config.mk $srcdir/buildflags.diff
  for PATCH in "${_patches[@]}"; do
    msg "${PATCH##*/}" && patch -Np1 dwm.c "$srcdir/${PATCH##*/}"
  done

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver

  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '5621a5627e402306fde977eee2183fb9'
         'b8de5bdd45e3736cf2e6b0277301e196'
         'af6c17f901ad910f1361ce1c25070b03'
         '14b0c80bab839935d6cab83a5e8bc147'
         'b583a32067f9a7c842877e9d8db3f228'
         '9f94d270898ac0dea4212ceb120ed3a6'
         'f099928846b74a600e4b24d7cfb61656'
         '455be45ad6a061f73faa8438ee4c917f'
         'b50db47f358e21b2c58399f6424d339a'
         'cfa58980d1924cd0959fc65323916144'
         'e43544c2ab6116efc5a7e2e21cb730e2'
         'bc7d12946c77113a7e9a73c99ef81b9f'
         'b2db1e0d0265d381a45c66f28d11c27d'
         '161ede77c64f21555db333f2212e9533'
         'cc215a75d74f8dc442ea23b151eb7e67'
         'b8b6883b4dabd2a4283cec153a2f97dc'
         'e3c4e9039974a97803d0071a7f0fb762'
         '99c608a822f3b43a065093ea7b8fee56'
         'fcc18a0c8a4b0183127e1c7c6da6fa86'
         'f0e7a4bb62a395942f435d613231c3b5'
         '6e94ec1bd6b4cb29eebffd5e7dd686f1')
