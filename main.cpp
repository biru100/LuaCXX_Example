#include <iostream>
#include <string>



extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#pragma comment (lib, "lua53.lib")

using namespace std;

int main(void)
{
	lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    string filename;
    string funcname;
    int count;

    cout << "파일 이름 : ";
    cin >> filename;
    cout << "함수 이름 : ";
    cin >> funcname;
    cout << "매개변수 갯수 : ";
    cin >> count;

	int res = luaL_dofile(L, filename.c_str());
    lua_getglobal(L, funcname.c_str());
    for (int i = 1; i <= count; i++)
    {
        int temp;
        cout << "매개변수 " << i << " : ";
        cin >> temp;
        lua_pushnumber(L, temp);
    }
    lua_call(L, count, 1);
    int num = lua_tointeger(L, lua_gettop(L));

    printf("결과값 : %d", num);

    cin >> count;

	lua_close(L);
    return 0;
}