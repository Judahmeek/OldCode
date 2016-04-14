#RGB to Hex
# http://www.codewars.com/kata/513e08acc600c94f01000001/train/ruby

def rgb_to_hex(*params)
  params.inject("") { |string, value| string << "#{[0, value, 255].sort!.at(1).to_s(16).rjust(2, '0')}" }.upcase
end