
-- 本测试不需要sys也能跑

local t = 0
local pre = [[
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
    1234567890
]]
while t < 10000 do
    local tab = {os.date(), pre, tostring(t)}
    log.info("main", table.concat(tab))
    t = t + 1
    --collectgarbage()
    timer.mdelay(5)
end