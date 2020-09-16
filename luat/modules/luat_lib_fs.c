
#include "luat_base.h"
#include "luat_fs.h"
#include "luat_malloc.h"

#define LUAT_LOG_TAG "luat.fs"
#include "luat_log.h"

/*
获取文件系统信息
@api    fs.fsstat(path)
@string 路径,默认"/",可选
@return boolean 获取成功返回true,否则返回false
@return int 总的block数量
@return int 已使用的block数量
@return int block的大小,单位字节
@return string 文件系统类型,例如lfs代表littlefs
@usage
-- 打印根分区的信息
log.info("fsstat", fs.fsstat("/"))
*/
static int l_fs_fsstat(lua_State *L) {
    const char* path = luaL_optstring(L, 1, "/");
    luat_fs_info_t info;
    if (luat_fs_info(path, &info) == 0) {
        lua_pushboolean(L, 1);
        lua_pushinteger(L, info.total_block);
        lua_pushinteger(L, info.block_used);
        lua_pushinteger(L, info.block_size);
        lua_pushstring(L, info.filesystem);
        return 5;
    } else {
        lua_pushboolean(L, 0);
        return 1;
    }
}

/*
获取文件大小
@api    fs.fsize(path)
@string 文件路径
@return int 文件大小,若获取失败会返回0
@usage
-- 打印main.luac的大小
log.info("fsize", fs.fsize("/main.luac"))
*/
static int l_fs_fsize(lua_State *L) {
    const char* path = luaL_checkstring(L, 1);
    lua_pushinteger(L, luat_fs_fsize(path));
    return 1;
}


static int l_fs_mkdir(lua_State *L) {
    const char* path = luaL_checkstring(L, 1);
    lua_pushinteger(L, luat_fs_mkdir(path));
    return 1;
}

static int l_fs_rmdir(lua_State *L) {
    const char* path = luaL_checkstring(L, 1);
    lua_pushinteger(L, luat_fs_rmdir(path));
    return 1;
}

static int l_fs_mkfs(lua_State *L) {
    luat_fs_conf_t conf = {0};
    conf.busname = luaL_checkstring(L, 1);
    conf.filesystem = luaL_checkstring(L, 2);
    lua_pushinteger(L, luat_fs_mkfs(&conf));
    return 1;
}

static int l_fs_mount(lua_State *L) {
    luat_fs_conf_t conf = {0};
    conf.busname = luaL_checkstring(L, 1);
    conf.filesystem = luaL_checkstring(L, 2);
    conf.mount_point = luaL_checkstring(L, 3);
    conf.type = luaL_checkstring(L, 4);
    lua_pushinteger(L, luat_fs_mount(&conf));
    return 1;
}

static int l_fs_umount(lua_State *L) {
    luat_fs_conf_t conf = {0};
    conf.mount_point = luaL_checkstring(L, 1);
    lua_pushinteger(L, luat_fs_umount(&conf));
    return 1;
}

#include "rotable.h"
static const rotable_Reg reg_fs[] =
{
    { "fsstat",      l_fs_fsstat,   0},
    { "fsize",       l_fs_fsize,    0},
    { "mkdir",       l_fs_mkdir,    0},
    { "rmdir",       l_fs_rmdir,    0},
    { "mkfs",        l_fs_mkfs,     0},
    { "mount",       l_fs_mount,    0},
    { "umount",      l_fs_umount,   0},
	{ NULL,                 NULL,   0}
};

LUAMOD_API int luaopen_fs( lua_State *L ) {
    rotable_newlib(L, reg_fs);
    return 1;
}
