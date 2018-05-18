require 'launchy'

class OpenUrl
  def set_url
    puts "URLを指定してください!"
    print "URL:"
    @url = gets.chomp
  end

  def open_url
    Launchy.open "#{@url}"
  end
end

Obj = OpenUrl.new
Obj.set_url
Obj.open_url
