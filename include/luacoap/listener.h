#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <smcp/smcp.h>

// Name for the Lua meta-table
#define LISTENER_MT_NAME "coap_listener"

/**
 *  Handle observation subscriptions
 */
typedef struct {
  smcp_t* smcp;
  int lua_func_ref; /**< Reference to the lua callback function */
} lcoap_listener;

/**
 *  Stores a reference in the listener structure to the object in the top of
 *  the stack of the lua state L.
 */
void store_callback_reference(lua_State* L, lcoap_listener* ltnr);

/**
 *  Call the function stored inside the listener.
 */
int execute_callback(lua_State* L, lcoap_listener* ltnr);

/**
 *  Register the listener table.
 */
void register_listener_table(lua_State *L);