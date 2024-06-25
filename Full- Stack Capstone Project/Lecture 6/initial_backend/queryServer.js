const express = require('express');
const app = express();
app.get("/query", function (req,res) {
    try {
        const query = req.query;
        res.status(200).json(query);
    } catch (error) {
        res.status(500).json({ error: 'Internal Server Error' });
    }
})
app.listen(3001, () => {
    console.log('Server is running on port 3001');
});