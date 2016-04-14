#Base Conversion
# http://www.codewars.com/kata/526a569ca578d7e6e300034e/train/ruby

def convert(input, source, target)
    number = input.chars.reverse.each_with_index.inject(0) { |sum, (element, index)| sum + source.index(element) * source.length ** index }
    result = number == 0 ? target[number] : ""
    until number == 0 do
      result << target[number % target.length]
      number /= target.length
    end
    result.reverse
end