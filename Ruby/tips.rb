require_relative 'basicserializable'
#require 'C:\Users\Mastermind\Documents\GitHub\OldCode\Ruby\tips'

module Rubytips
	class Tips
		include BasicSerializable

		@tips

		def initialize
			@tips = Hash.new
		end

		def from_file
			@tips.merge(unserialize(File.read('ruby_tips')))
		end

		def to_file
			File.open('C:\Users\Mastermind\Documents\GitHub\OldCode\Ruby\ruby_tips', 'w') { |file| file.write(self.serialize) }
		end

		def add_tip(key, tip)
			@tips[key] = tip
		end
	end
end