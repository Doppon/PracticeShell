require 'launchy'

puts "URLを指定してください!"
print "URL:"; url = gets.chomp

Launchy.open "#{url}"
