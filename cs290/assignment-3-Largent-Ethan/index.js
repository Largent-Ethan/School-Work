/*
 * Add your JavaScript to this file to complete the assignment.  Don't forget
 * to add your name and @oregonstate email address below.
 *
 * Name: Ethan Largent
 * Email: largenet@oregonstate.edu
 */

/*
 NEW TWIT CREATION FUNCTIONS
*/
function addTwit(twitTextInput, twitAuthorInput, addToData) {
    var newTwit = document.createElement('article')
    newTwit.classList.add('twit')
    var twitIconDiv = document.createElement('div')
    twitIconDiv.classList.add('twit-icon')
    var twitIcon = document.createElement('i')
    twitIcon.classList.add('fas')
    twitIcon.classList.add('fa-bullhorn')
    var twitContent = document.createElement('div')
    twitContent.classList.add('twit-content')
    var twitText = document.createElement('p')
    twitText.classList.add('twit-text')
    var twitAuthor = document.createElement('p')
    twitAuthor.classList.add('twit-author')
    var twitAuthorLink = document.createElement('a')

    twitAuthorLink.href = "#"
    twitText.textContent = twitTextInput
    twitAuthorLink.textContent = twitAuthorInput

    twitIconDiv.appendChild(twitIcon)
    twitAuthor.appendChild(twitAuthorLink)
    twitContent.appendChild(twitText)
    twitContent.appendChild(twitAuthor)
    newTwit.appendChild(twitIconDiv)
    newTwit.appendChild(twitContent)
    twitContainer.appendChild(newTwit)

    if(addToData)
        twitData.push(getTwitData(newTwit))
}

function addTwitInterfaceAppear(event) {
    document.getElementById('modal-backdrop').classList.remove('hidden')
    document.getElementById('create-twit-modal').classList.remove('hidden')
    document.getElementById('twit-text-input').focus()
}

function addTwitInterfaceDisappear(event) {
    document.getElementById('modal-backdrop').classList.add('hidden')
    document.getElementById('create-twit-modal').classList.add('hidden')
}

function clearTextBox(event) {
    document.getElementById('twit-text-input').value = ""
}

function clearAuthorBox(event) {
    document.getElementById('twit-attribution-input').value = ""
}

function submitTwit(event){
    var twitTextInput = document.getElementById('twit-text-input').value
    var twitAuthorInput = document.getElementById('twit-attribution-input').value
    if (twitAuthorInput != "" && twitTextInput != "") {
        addTwit(twitTextInput, twitAuthorInput, true)
        document.getElementById('twit-text-input').value = ""
        document.getElementById('twit-attribution-input').value = ""
        addTwitInterfaceDisappear(event)
    }
    else {
        if(twitTextInput == "")
            document.getElementById('twit-text-input').value = "Field cannot be empty"
        if(twitAuthorInput == "")
            document.getElementById('twit-attribution-input').value = "Field cannot be empty"
    }
}

/*
 TWIT SEARCH FUNCTIONS
*/
function getTwitData(twit) {
    var text = twit.getElementsByClassName('twit-text')[0].textContent.trim()
    var author = twit.getElementsByClassName('twit-author')[0].textContent.trim()
    var newTwit = new Twit(text, author)
    return newTwit
}

function updateSearchResults(event) {
    var search = document.getElementById('navbar-search-input').value.toLowerCase()
    var currText
    var currAuthor
    var numTwits = twitData.length
    twitContainer.innerHTML = ""
    for (var i = 0; i < numTwits; i++) {
        currText = twitData[i].getText()
        currAuthor = twitData[i].getAuthor()
        if(currText.toLowerCase().includes(search) || currAuthor.toLowerCase().includes(search))
            addTwit(currText, currAuthor, false)
    }
}

/*
 CLASS AND VARIABLE DECLARATIONS
*/
function Twit(text, author) {
    this.text = text
    this.author = author
}

Twit.prototype.getText = function() {
    return this.text
}

Twit.prototype.getAuthor = function() {
    return this.author
}

var twitContainer = document.getElementsByClassName("twit-container")[0]

var twits = document.getElementsByClassName('twit')
var twitData = []
for (var i = 0; i < twits.length; i++) {
    twitData.push(getTwitData(twits[i]))
}

console.log(twitData)

/*
 EVENT TRACKING
*/
//Create Twit Button
document.getElementById('create-twit-button').addEventListener('click', addTwitInterfaceAppear)
//Close Twit Creation Button
document.getElementsByClassName('modal-close-button')[0].addEventListener('click', addTwitInterfaceDisappear)
//Cancel Twit Creation Button
document.getElementsByClassName('modal-cancel-button')[0].addEventListener('click', addTwitInterfaceDisappear)
//Accept Twit Creation Button
document.getElementsByClassName('modal-accept-button')[0].addEventListener('click', submitTwit)
//On Twit Text Box Click
document.getElementById('twit-text-input').addEventListener('click', clearTextBox)
//On Author Text Box Click
document.getElementById('twit-attribution-input').addEventListener('click', clearAuthorBox)
//Update Search Results
document.getElementById('navbar-search-input').addEventListener('keyup', updateSearchResults)