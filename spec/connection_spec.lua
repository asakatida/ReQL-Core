local r = require('libReQL')

describe('connection', function()
  it('basic', function()
    r.connect(function(err, c)
      if err then error(err.message) end
      assert.are_not.equal(c, nil)
    end)
  end)
end)
