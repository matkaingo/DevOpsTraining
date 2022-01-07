const express = require('express');
const app = express();


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

app.listen(port, () => {
    console.log('Server started on port ' + port);
});