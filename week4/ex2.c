#include <stdio.h>
#include <unistd.h>

int main() {
	for (int i = 0; i < 3; ++i) {
		fork();
		sleep(5);
	}
	
	return 0;
}

/* The output is the following. As you can see the number of processes are 8 (2^3), this is exactly how many time we called fork.

artembakhanov@artem-pc ~/week4> pstree
systemd─┬─ModemManager───2*[{ModemManager}]
        ├─NetworkManager───2*[{NetworkManager}]
        ├─agent───2*[{agent}]
        ├─avahi-daemon───avahi-daemon
        ├─baloo_file───2*[{baloo_file}]
        ├─bluetoothd
        ├─crond
        ├─cupsd
        ├─dbus-daemon
        ├─gmenudbusmenupr───2*[{gmenudbusmenupr}]
        ├─kdeconnectd───3*[{kdeconnectd}]
        ├─kdeinit5─┬─2*[file.so]
        │          ├─firefox─┬─2*[Web Content───36*[{Web Content}]]
        │          │         ├─2*[Web Content───34*[{Web Content}]]
        │          │         ├─Web Content───37*[{Web Content}]
        │          │         ├─Web Content───41*[{Web Content}]
        │          │         ├─Web Content───33*[{Web Content}]
        │          │         ├─Web Content───23*[{Web Content}]
        │          │         ├─WebExtensions───30*[{WebExtensions}]
        │          │         ├─file:// Content───30*[{file:// Content}]
        │          │         └─74*[{firefox}]
        │          ├─kaccess───2*[{kaccess}]
        │          ├─kded5───5*[{kded5}]
        │          ├─klauncher───2*[{klauncher}]
        │          ├─konsole─┬─bash───fish─┬─ex2─┬─ex2─┬─ex2───ex2
        │          │         │             │     │     └─ex2
        │          │         │             │     ├─ex2───ex2
        │          │         │             │     └─ex2
        │          │         │             └─pstree
        │          │         └─3*[{konsole}]
        │          ├─ksmserver─┬─kwin_x11───7*[{kwin_x11}]
        │          │           └─2*[{ksmserver}]
        │          ├─msm_kde_notifie───2*[{msm_kde_notifie}]
        │          ├─okular───3*[{okular}]
        │          └─yakuake─┬─bash
        │                    └─3*[{yakuake}]
        ├─krunner───4*[{krunner}]
        ├─kwalletd5───2*[{kwalletd5}]
        ├─lvmetad
        ├─okular───3*[{okular}]
        ├─org_kde_powerde───4*[{org_kde_powerde}]
        ├─plasmashell─┬─ksysguardd
        │             └─11*[{plasmashell}]
        ├─polkit-kde-auth───4*[{polkit-kde-auth}]
        ├─polkitd───11*[{polkitd}]
        ├─rtkit-daemon───2*[{rtkit-daemon}]
        ├─sddm─┬─Xorg───4*[{Xorg}]
        │      ├─sddm-helper───startkde───kwrapper5
        │      └─{sddm}
        ├─start_kdeinit
        ├─systemd─┬─(sd-pam)
        │         ├─at-spi-bus-laun─┬─dbus-daemon
        │         │                 └─3*[{at-spi-bus-laun}]
        │         ├─at-spi2-registr───2*[{at-spi2-registr}]
        │         ├─dbus-daemon
        │         ├─dconf-service───2*[{dconf-service}]
        │         ├─gvfsd───2*[{gvfsd}]
        │         ├─gvfsd-fuse───5*[{gvfsd-fuse}]
        │         ├─gvfsd-metadata───2*[{gvfsd-metadata}]
        │         ├─kactivitymanage───5*[{kactivitymanage}]
        │         ├─kglobalaccel5───2*[{kglobalaccel5}]
        │         ├─kscreen_backend───2*[{kscreen_backend}]
        │         ├─obexd
        │         └─pulseaudio─┬─gsettings-helpe───3*[{gsettings-helpe}]
        │                      └─2*[{pulseaudio}]
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-udevd
        ├─udisksd───4*[{udisksd}]
        ├─upowerd───2*[{upowerd}]
        ├─wpa_supplicant
        ├─xclip
        └─xembedsniproxy───2*[{xembedsniproxy}]
Job 1, './ex2 &' has ended
*/