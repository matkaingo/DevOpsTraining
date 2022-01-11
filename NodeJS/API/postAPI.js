const express = require('express');
const app = express();
const mysql = require('mysql');

var con = mysql.createConnection({
    host     : 'localhost',
  user     : 'root',
  password : '123456789',
  database : 'testdb'
  });
  
  con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
  });  
  

const port = process.env.PORT || 3000;

app.get('/', (req, res) =>{
    console.log(req);
    res.send('This was a Get request');
});

app.get('/sum', (req, res) =>{
    console.log(req);
    const num1 = req.query.num1;
    const num2 = req.query.num2;
    const Message = req.query.message;
    res.send(`${num1} + ${num2} = ${Number(num1)+Number(num2)} -----------${Message}`);
});


app.post('/', (req, res) =>{
    console.log(req);
    res.send('This was a Post request');
});

app.post('/sql', (req, res) =>{
    console.log(req);
   const id = req.query.id;
    const last_name = req.query.last;
    const first_name = req.query.first;
    const favorite_website = req.query.web;

    const sql = `INSERT INTO customers (customer_id, last_name, first_name, favorite_website) VALUES (${Number(id)}, "${last_name}", "${first_name}", "${favorite_website}")`;
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log("1 record inserted");
      });
    res.send('This was a Post request');
});

app.listen(port, () => {
    console.log('Server started on port ' + port);
});