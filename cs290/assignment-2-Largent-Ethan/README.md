# Assignment 2

**Assignment and Code Blog Entry due at 11:59pm on Monday 4/25/2022**<br />
**Demo due by 11:59pm on Monday 5/9/2022**

The goals of this assignment are to exercise your CSS skills and to give you practice at implementing a page that visualy matches a set of provided "mocks", which is a common task for a web developer.

Here, you are provided with an un-styled `index.html` file, an empty `style.css` file, and a set of mocks (actually screenshots/captures) in the `mocks/` directory.  Your task is to add styles to `style.css` to make your rendered `index.html` page matches the mocks as closely as possible.  Below are listed some of the things you must accomplish.

## Text styling

* The font for the entire page should be [Roboto](https://fonts.google.com/specimen/Roboto).  A third-party stylesheet is included in `index.html` to import this font from Google Fonts.

* Note the different font weights used across the page in the mocks.  The font weight in the header is different than the font weight of the each twit's text, which in turn is different than the font weight of each twit's author.

* Pay attention to text alignment in the various elements of the page.

## Navbar

* The links in the navbar should have space around them.

* The search box and search button should be pushed all the way to the right of the navbar, while the other links should remain on the left side.

* The "active" navbar link should be indicated with an underline.

* When the user hovers over the navbar links or the search button their color should change to highlight the hovered element.

* When the search box is focused, its background color should change to indicate its focus.  The unfocused search box should have a slightly dimmer background color.

## Twits

* The twit layout should be somewhat responsive to the size of the browser viewport, in that columns should be added and removed as the size of the browser viewport changes.  Note that there should be equal space between all twits, both vertically and horizontally.

* Try to style your page so all twits in the same row have the same height.

* Pay attention to the alignment of elements within a single twit.  The top of the bullhorn icon should line up with the top of the twit text, and the right edge of the twit author should line up with the right edge of the twit itself (with just a bit of space between the edge of the author and the edge of the twit).

* Each twit should have a subtle border to help it stand out from the background.

* Note that the background behind the twits should not be pure white but a light gray.

* When the user hovers over a twit author, its color should change to highlight the hovered element.

## Add-twit button

* The location of the "add-twit" button should not not change relative to the viewport, even as the page is scrolled.

* The add-twit button itself should be a perfect circle.

* The add-twit button should have a subtle shadow behind it, to make it appear to be elevated slightly above the rest of the page.

* When the user hovers over the add-twit button, it should grow slightly and change color to indicate its interactivity.  The mouse cursor should change to a pointing hand.  When implementing CSS to make the add-twit button grow on hover, try to make it grow from the center instead of from the corner.

## Other notes on styling

* Again, your goal is to match the mocks as closely as possible.  I'll show some tools in class that will help you do this.  Don't worry, however, if you don't get things like padding, margins, etc. exactly right (e.g. matching the mocks to the exact pixel value).  Also, note that many style effects can be achieved in different ways using CSS.  However you implement various style features, the important thing is that they match the mocks as closely as possible.

* One other thing to note is that the page incorporates several icons from the [Font Awesome icon library](https://fontawesome.com/icons?d=gallery).  This library is incorporated as a 3rd-party CSS file, and the icons are placed into the page using `<i>` elements whose HTML classes indicate which icon to display what icon style to use (e.g. `far`, `fas`, `fa-hand-lizard`, etc.).  Do not use these classes to apply styles to the page or apply styles directly to the `<i>` elements.  You should be apply styles to other elements to match the appearance of the mocks.

## Code blog

Add an entry to your Code Blog reflecting on your experience with this assignment.  Here are some questions you could answer (though these aren't the only ones):

  * What was challenging about the assignment, and what specific kinds of problems did you have.  How did you solve those problems?

  * What did you learn from the assignment?  Were there any special insights you had?  What did you find that you already knew?

  * What kinds of resources were helpful for completing the assignment?  Specific websites?  Lectures?  The class Campuswire forum?  The TAs?  How did you use each of these resources?

  * What are one or two things you had to Google to complete the assignment?

## Submission

As always, we'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub.  Just make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom.  A good way to check whether your files are safely submitted is to look at the master branch your assignment repo on the github.com website (i.e. https://github.com/osu-cs290-sp22/assignment-2-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

In addition to submitting your assignment via GitHub, you must submit the URL to your code blog entry (e.g. http://web.engr.oregonstate.edu/~YOUR_ONID_ID/cs290/blog.html) via Canvas by the due date specified above.

## Grading criteria

Note that only changes to `style.css` will be considered when grading this assignment.  Any changes you make to `index.html` will be ignored.

The assignment is worth 100 points total:

* Header and navbar: 40 points
  * 5 points: colors in header and navbar match mocks
  * 5 points: text styling in header and navbar matches mocks
  * 5 points: size, spacing (around and inside), and relative positioning of navbar and header elements matches mocks
  * 10 points: navbar contents are laid out according to mocks (links on the left and search on the right)
  * 5 points: "active" navbar link highlighted as in mocks
  * 5 points: interactions with navbar links (e.g. hover) match mocks
  * 5 points: search box interactions (e.g. hover and focus) match mocks

* Twits: 40 points
  * 5 points: colors inside and surrounding twits match mocks
  * 5 points: text styling in twits matches mocks
  * 5 points: size, spacing (around and inside) and relative positioning of twits matches mocks
  * 5 points: layout of an individual twit matches mocks (e.g. text and icon alignment)
  * 10 points: all twits are laid out in columns, as in mocks
  * 5 points: number of twit columns adapts to the available viewport size
  * 5 points: interactions with twits (e.g. hover) match mocks

* Add-twit button: 20 points
  * 5 points: colors in add-twit button match mocks
  * 5 points: size, spacing (around and inside), and relative positioning of add-twit button matches mocks
  * 5 points: additional styling (e.g. circularity, shadow) of add-twit button match mocks
  * 5 points: interactions with add-twit button (e.g. hover) match mocks

In addition to your programming assignment grade, you will receive a pass/fail grade for your code blog entry, included in the code blog portion of your grade.
