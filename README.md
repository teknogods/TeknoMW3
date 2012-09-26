## Notes:
* Everything here is released under GPLv3.
* No further developmend planned

## Known bugs:
* Server list entries are not sanity-checked. This potentially allows 'hackers' to host a dedicated server that would crash the client(s) game process (when it's trying to add the faulty server to the list).

## TODO:
* Support for the latest build of the dedicated server (different calling convention, requires new hooks).
* Anti-Cheat
  - A global white-list perhaps? Allowing only legit players to play: go to website, register, get ID.key, put into game folder, play. ID.key gets globally revoked after X number of bans.
  - In-process cheat scanner?
    