{
  description = "STM32 dev shell with ARM GCC toolchain";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          gcc-arm-embedded
          cmake
          ninja
          gdb
          openocd
          uv
        ];

        shellHook = ''
          echo "STM32 dev shell ready"
          echo "Using compiler: $(which arm-none-eabi-gcc)"
        '';
      };
    };
}
