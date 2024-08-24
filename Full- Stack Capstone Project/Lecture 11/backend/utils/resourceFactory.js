
const createResourceFactory = (model) => {
    return async function create(req, res) {
        try {
            const resourceDetails = req.body;
            const resource = await model.create(resourceDetails);
            res.status(201).json({
                status: "successfull",
                message: `added  the resource `,
                resource: resource
            })
        } catch (err) {
            console.log(err);
            res.status(502).json({
                status: "failure",
                message: err.message
            })
        }
    }
}
const getAllResourceFactory = (model) => {
    return async function getAllProducts(req, res) {
        try {
            const queryObject = req.query;
            let sort = queryObject.sort;
            let page = queryObject.page || 1;
            let limit = queryObject.limit || 20;
            /****
             * 1. sort -> parameter normally -> asc , - -> desc  
             * 2. limit -> number of elements
             * 3. skip   -> number of elements to skip
             * ***/
            // find 
            let query = model.find();

            if (sort) {
                // find those properties that need to be sorted
                let [parameter, order] = sort.split("_");
                order = order === "desc" ? -1 : 1;
                console.log(parameter, order);
                query = query.sort({ [parameter]: order });
            }

            const elementsToSkip = (page - 1) * limit;
            query = query.skip(elementsToSkip)
                .limit(limit);

            const listOfResources = await query;


            res.status(200).json({
                status: "successfull",
                message: `list of the resource `,
                ResourceList: listOfResources
            })
        } catch (err) {
            res.status(404).json({
                status: "failure",
                message: err.message
            })
        }
    }
}
const getResourceByIdFactory = (model) => {
    return async function (req, res) {
        try {
            const id = req.params.id
            const resource = await model.findById(id);
            if (resource) {
                if (resource.password) {
                    resource.password = undefined;
                }
                res.status(200).json({
                    status: "successfull",
                    message: `got the resource `,
                    resource: resource
                })
            } else {
                throw new Error("Product not found");
            }
        } catch (err) {
            res.status(404).json({
                status: "failure",
                message: err.message
            })
        }
    }
}
const deleteResourceByIdFactory = (model) => {
    return async function deleteProductById(req, res) {
        try {
            const id = req.params.id;
            const product = await model.findByIdAndDelete(id);
            if (product) {
                res.status(200).json({
                    status: "successfull",
                    message: `product is deleted`,
                    product: product
                })
            } else {
                throw new Error("Product not found");
            }
        } catch (err) {
            res.status(404).json({
                status: "failure",
                message: err.message
            })
        }
    }
}
const updateResourceByIdFactory = (model) => {
    return async function updateProductById(req, res) {
        try {
            /***
             * 1. you will need -> id 
             * 2. you have pass the keys that they want to update
             * **/
            const id = req.params.id;
            const toUpdateObject = req.body;
            /**
             * some sanitation
             * *  should not be any keys that are not following our schema, _id
             * **/
            const product = await model.findByIdAndUpdate(id, toUpdateObject, { new: true });
            if (product) {
                res.status(200).json({
                    status: "successfull",
                    message: `product was updated`,
                    product: product
                })
            } else {
                throw new Error("Product not found");
            }

        } catch (err) {
            res.status(404).json({
                status: "failure",
                message: err.message
            })
        }
    }
}
module.exports = {
    createResourceFactory,
    getAllResourceFactory,
    getResourceByIdFactory,
    deleteResourceByIdFactory,
    updateResourceByIdFactory
}