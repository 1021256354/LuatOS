local sys = require "sys"

print(_VERSION)

sys.timerStartLoop(function()
    print("hi, LuatOS")
end, 3000)

sys.run()
