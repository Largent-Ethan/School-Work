# Assignment 3

**Assignment and Code Blog entry due at 11:59pm on Monday, 5/9/2022**<br />
**Demo due by 11:59pm on Monday, 5/23/2022**

The goal of this assignment is to start using JavaScript on the client to add interactions to a web page, including reacting to user-generated events and manipulating the DOM.  We will build off of our work from Assignment 2.

Here, you are provided with an `index.html` file and a `style.css` file that, combined, give you the "Tweeter" page we worked on in Assignment 2 (plus a little extra that we'll use in this assignment).  You're also given an empty `index.js` file.  Your job is to complete `index.js` to add interactions to the page, as described below.

## 1. Support inserting new twits

First, you'll add some functionality to the Tweeter page to allow the user to create new twits on the client.  This should work as follows:

1. Clicking on the red "create twit" button should display a modal that allows you to write a new twit.  The modal (along with a backdrop that goes behind it to shade the underlying page while the modal is displayed) are both already included in the HTML code, so you don't have to create them from scratch, but they are hidden when the page is first loaded.  Clicking the red "create twit" button should un-hide them.  You'll have to examine the HTML to figure out the relevant IDs/classes to use to accomplish this.

2. When the modal is open, clicking the modal close button (the small "X" in the upper-right corner) or the modal cancel button (the one in the modal footer that says "Cancel") should close the modal by re-hiding it and the backdrop.  When the modal is closed, the values of all of the input fields should be cleared so they don't appear the next time the modal is opened.

3. When the modal is open, clicking the modal accept button (the one in the modal footer that says "Create Twit") should close the modal and generate a new twit that is placed inside the twit container *after* all of the other existing ones.  The new twit should match the structure of the existing twits so it is styled correctly.  Here is what the structure of the twit should look like:

    ```
    <article class="twit">
      <div class="twit-icon">
        <i class="fa fa-bullhorn"></i>
      </div>
      <div class="twit-content">
        <p class="twit-text">
          <--! Put the twit text entered by the user here. -->
        </p>
        <p class="twit-author">
          <a href="#"><--! Put the twit author entered by the user here. --></a>
        </p>
      </div>
    </article>
    ```

    **Importantly, you should not use `innerHTML` to generate DOM content directly from user-input content, since this opens up a vulnerability to cross-site scripting attacks. You must ensure that user-input content is safely added into the DOM.**

    When the new twit is created and the modal is closed, the values of all of the input fields should be cleared so they don't appear the next time the modal is opened.

4. If the user clicks the modal accept button while either of the input fields is blank, the user should be alerted (using the [`alert()` function](https://developer.mozilla.org/en-US/docs/Web/API/Window/alert)), and the modal should be kept open until the user either closes/cancels it or provides values for both input fields.  A new twit should not be created if the user hasn't specified values for both fields.

## 2. Support twit searches

When the user enters a search query into the search box in the navbar and clicks the search button (the little magnifying glass in the navbar), any twits whose text or author don't contain the specified search query should be removed from the DOM (*completely* removed from the DOM, not just hidden), leaving only the ones that match the search query being displayed.  Importantly, your search should be case insensitive.  For example, if the user enters the string "abc" in the search box, twits containing all of the following substrings should be considered as matching the search query: "abc", "ABC", "Abc", "aBC", etc.  In addition, the search query should be matched all text within the twits, including both the twit text and the twit author.

In addition, for full credit, you must implement both of the following features:

  * **Enable re-searching** - If the user changes the search query and hits the search button, the search should be performed over all of the original twits and any newly added ones.  This means that twits that were removed from the DOM because of a previous search might have to be re-added back into the DOM.  If the user clears the search term completely, all of the original twits and any newly added ones should be displayed again.  In all cases, the twits should always remain in the same order relative to each other.

  * **Enable "live search"** - Hook the search box up so that the search results are updated with each character the user types, even without hitting the search button.  In this case, the search results should behave as described just above, with twits being re-added into and removed from the DOM as appropriate.  In other words, each new character inserted or deleted could potentially result in a change to the displayed twits.

## Code Blog

Add an entry to your Code Blog reflecting on your experience with this assignment.  Here are some questions you could answer (though these aren't the only ones):

  * What was challenging about the assignment, and what specific kinds of problems did you have.  How did you solve those problems?

  * What did you learn from the assignment?  Were there any special insights you had?  What did you find that you already knew?

  * What kinds of resources were helpful for completing the assignment?  Specific websites?  Lectures?  The class Piazza forum?  The TAs?  How did you use each of these resources?

  * What are one or two things you had to Google to complete the assignment?

## Submission

As always, we'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub.  Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom.  A good way to check whether your files are safely submitted is to look at the master branch your assignment repo on the github.com website (i.e. https://github.com/osu-cs290-sp22/assignment-3-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

In addition to submitting your assignment via GitHub, you must submit the URL to your code blog entry (e.g. http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/blog.html) via Canvas by the due date specified above.  Make sure to submit your code blog URL on Canvas even if it's the same URL where you've published previous code blog entries.

## Grading criteria

This assignment will be graded based only your `index.js` file, and any changes you make to `index.html` or `style.css` will be ignored.

The assignment is worth 100 points total:

  * New twit creation: 65 points:

    * 10 points: clicking the red "create twit" button displays the modal and its backdrop

    * 10 points: clicking either the modal's close button or the modal's cancel button hits the modal and backdrop

    * 30 points: clicking the modal's accept button adds a correctly-formatted new twit to the end of the page if the user has specified values for the required input fields

    * 5 points: when creating a new twit, the page is not vulnerable to a cross-site scripting attack via user-supplied values

    * 5 points: clicking the modal's accept button when a value is not specified by the user for any one of the input fields results in the user being alerted and the modal remaining open

    * 5 points: whenever the modal is closed (either when a twit is created or not), any input values the user specified are cleared so they do not appear when the modal is opened the next time

  * Twit search: 35 points

    * 5 points: client-side JS correctly reads search term input by the user

    * 15 points: user-supplied search term is correctly applied to filter the twits when the user clicks the "search" button, with non-matching twits removed completely from the DOM (not just hidden)

    * 10 points: re-searching is enabled, i.e. when the user changes the search query and hits the search button, all matching twits are displayed, even ones that were removed from the DOM based on a previous search

    * 5 points: "live" search is enabled, i.e. search results update as the user types, as described above
