# Sudoku Solution Validator
# http://www.codewars.com/kata/53db96041f1a7d32dc0004d2/train/ruby

def cut_up(board)
  res = Array.new(3) {Array.new(3) {Array.new}}
  board.each_with_index { |row, ri| row.each_with_index { |e, i| res[ri/3][i/3] << e }}
  res
end

def check(x)
  x.all? { |row| row.reduce(0) { |res, x| res + 2 ** (x - 1) } == 511 }
end

def done_or_not(board)
  (check(board) and check(board.transpose) and check(cut_up(board).flatten!(1))) ? "Finished!" : "Try again!"
end