{ pkgs ? import <nixpkgs> { config = { allowUnsupportedSystem = true; }; }
, avr ? true, arm ? false, teensy ? true }:

with pkgs;

mkShell {
  name = "qmk-firmware";

  # pkgsCross.avr's gcc wrapper bundles avr-binutils and avr-libc, so it
  # no longer needs the manual -isystem/-B/-L avrlibc flags.
  packages = [ dfu-programmer dfu-util diffutils git gnumake ]
    ++ lib.optionals avr [ pkgsCross.avr.buildPackages.gcc avrdude ]
    ++ lib.optionals arm [ gcc-arm-embedded ]
    ++ lib.optionals teensy [ teensy-loader-cli ];

  # This 2018-era tree trips newer gcc warnings (e.g. -Wheader-guard in
  # tmk_core/common/command.h) and builds with -Werror. make picks this up
  # from the environment; tmk_core/rules.mk appends it to every compile.
  EXTRAFLAGS = "-Wno-error";
}
