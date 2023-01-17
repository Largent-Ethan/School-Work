module.exports = function() {
    var express = require('express');
    var router = express.Router();
    function getProjects(res, mysql, context, complete) {
        mysql.pool.query("SELECT Pnumber, Pname FROM PROJECT", function(error, results, fields) {
            if(error) {
                res.write(JSON.stringify(error));
                res.end();
            }
            context.projects = results;
            complete();
        });
    }

    function getEmployees(res, mysql, context, complete) {
        mysql.pool.query("SELECT Fname, Lname, Salary, Dno FROM EMPLOYEE", function(error, results, fields) {
            if(error) {
                res.write(JSON.stringify(error));
                res.end();
            }
            context.employees = results;
            complete();
        });
    }

    // function getEmployeeByProject() {

    // }

    // function getProjectInfo() {

    // }

    function getEmployeeWithNameLike(res, mysql, context, Fname, complete) {
        var sql = "SELECT Fname, Lname, Salary, Dno FROM EMPLOYEE WHERE Fname = ?";
        var inserts = [Fname];
        mysql.pool.query(sql, inserts, function(error, results, fields) {
            if(error) {
                res.write(JSON.stringify(error));
                res.end();
            }
            context.employees = results;
            complete();
        })
    }

    router.get('/', function(req, res) {
        var callbackCount = 0;
        var context = {};
        context.jsscripts = ["deleteemployee.js"];
        var mysql = req.app.get('mysql');
        getEmployees(res, mysql, context, complete);
        getProjects(res, mysql, context, complete);
        function complete() {
            callbackCount++;
            if(callbackCount >= 2) {
                res.render('employees', context);
            }
        }
    });


    // router.get('/filter/:project', function(req, res) {});


    // router.get('/search/:s', function(req, res) {});
}