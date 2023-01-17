/*
 * Write your server code in this file.  Don't forget to add your name and
 * @oregonstate.edu email address below, so we know whose code we're grading.
 *
 * name: Ethan Largent
 * email: largenet@oregonstate.edu
 */

var http = require('http')
var fs = require('fs')
console.log('== reading index.html')
var index_html = fs.readFileSync('public/index.html', 'utf8')
console.log('== reading index.js')
var index_js = fs.readFileSync('public/index.js', 'utf8')
console.log('== reading style.css')
var style_css = fs.readFileSync('public/style.css', 'utf8')
console.log('== reading 404.html')
var error404_html = fs.readFileSync('public/404.html', 'utf8')
console.log('== all files read')

var server = http.createServer(function (req, res) {
    console.log("== A request was recieved")
    console.log("  - req.method:", req.method)
    console.log("  - req.url:", req.url)
    console.log("  - req/headers:", req.headers)
    if(req.url === '/index.html' || req.url === '/') {
        res.setHeader('Content-Type', 'text/html')
        console.log('== index.html page retrieved')
        res.statusCode = 200
        res.write(index_html)
    } else if(req.url === '/index.js') {
        res.setHeader('Content-Type', 'application/javascript')
        console.log('== index.js page retrieved')
        res.statusCode = 200
        res.write(index_js)
    } else if(req.url === '/style.css') {
        res.setHeader('Content-Type', 'text/css')
        console.log('== style.css page retrieved')
        res.statusCode = 200
        res.write(style_css)
    } else {
        res.setHeader('Content-Type', 'text/html')
        console.log('== 404.html page retrieved')
        res.statusCode = 404
        res.write(error404_html)
    }
    res.end()
})

server.listen(3000, function () {
    console.log("== Server is listening")
})