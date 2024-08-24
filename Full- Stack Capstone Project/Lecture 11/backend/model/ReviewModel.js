
const mongoose = require("mongoose");
const reviewSchemaRules = {
    createAt: {
        type: Date,
        default: Date.now()
    },
    rating: {
        type: Number,
        required: true,
        min: [1, "rating can not be less than 1"],
        max: [5, "rating can not be more than 5"]
    },
    review_title: {
        type: String,
        required: true,
    },
    review_desc: {
        type: String,
        required: true,
    },
    // will be given to you by razorpay 
    averageRating: {
        type: Number,
        max: [5, "avg rating can not be more than 5"],
        min: [1, "rating can not be less than 1"],

    },
    // we are specifying that -> 
    // user is a reference to the UserModel
    user: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "UserModel"
    },
    // we are specifying that -> 
    // product is a reference to the ProductModel
    product: {
        type: mongoose.Schema.ObjectId,
        required: true,
        ref: "ProductModel"
    },


}
const reviewSchema = new mongoose.Schema(reviewSchemaRules);

const ReviewModel = new mongoose.model("ReviewModel", reviewSchema);
// place where all the reviews will go while following the schems
module.exports = ReviewModel;