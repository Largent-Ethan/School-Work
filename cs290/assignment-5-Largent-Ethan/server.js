/*
 * Write your routing code in this file.  Make sure to add your name and
 * @oregonstate.edu email address below.
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

var path = require('path')
var express = require('express')
var exphbs = require('express-handlebars')

var twitData = require('./twitData.json')

var port = process.env.PORT || 3000
var app = express()

app.engine('handlebars', exphbs.engine({ defaultLayout: null}))
app.set('view engine', 'handlebars')

app.use(express.static('public'))

//Request Home Page
app.get('/', function (req, res, next) {
  res.status(200).render('page', {
    renderTwits: true,
    renderButton: true,
    twits: twitData,
  })
})

//Request Twit Page
app.get('/twits/:number', function (req, res, next) {
  var number = req.params.number;
  if(twitData.length <= number || number < 0) {
    next()
  }
  var twit = [twitData[number]]
  res.status(200).render('page', {
    renderTwits: true,
    renderButton: false,
    twits: twit
  })
})

//Invalid Page Request
app.get('*', function (req, res, next) {
  res.status(404).render('page', {
    renderTwit: false,
    renderButton: false,
  })
})

app.listen(port, function () {
  console.log("== Server is listening on port", port)
})