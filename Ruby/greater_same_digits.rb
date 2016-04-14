#Next greater number w/ same digits
# http://www.codewars.com/kata/55983863da40caa2c900004e/train/ruby

def next_bigger(n)
  n = n.to_s
  small = n.chars.each_with_index.select { |each, index| each < n[[index + 1, n.length - 1].min] }.last
  return -1 unless small
  big = n.chars.rindex { |x| x > small[0] }
  n[small[1]] = n[big]
  n[big] = small[0]
  "#{n[0..small[1]]}#{n[(small[1]+1)...n.length].chars.sort.join}".to_i
end