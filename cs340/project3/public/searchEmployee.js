function searchEmployeeByFirstName() {
    //get the first name
    var first_name_search_string = document.getElementById('first_name_search_string').value;
    //construct the URL and redirect to it
    if (first_name_search_string !== '') {
        window.location = '/employee/search/' + encodeURL(first_name_search_string);
    } else {
        window.location = '/employee';
    }
}