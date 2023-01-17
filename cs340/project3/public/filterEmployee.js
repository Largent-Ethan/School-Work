function filterEmployeeByProject() {
    //get the pno of the selected project from the filter dropdown
    var project_pno = document.getElementById('project_filter').value;
    //construct the URL and redirecct to it
    window.location = '/employee/filter/' + parseInt(project_pno);
}