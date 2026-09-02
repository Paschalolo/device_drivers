savedcmd_src/Hello.mod := printf '%s\n'   src/Hello.o | awk '!x[$$0]++ { print("./"$$0) }' > src/Hello.mod
