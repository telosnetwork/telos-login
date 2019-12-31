# Contract API

The login contract has two actions: `login()` and `logout()`:

### Login

Authenticates the user and creates a login event. An external server can query the login row to verify authentication. A login code can be supplied by the app as a validation reference.

`cleos push action exampleacct1 login '["exampleacct1", "abcxyz123"]' -p exampleacct1`

### Logout

Finds a login row and deletes it. Returns RAM back to the user.

`cleos push action exampleacct1 logout '["exampleacct1"]' -p exampleacct1`