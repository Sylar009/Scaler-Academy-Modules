import React, { useEffect, useState } from "react";
import URL_CONFIG from "../constants/API_config";
import { useParams } from "react-router-dom";
import axios from "axios";

function ProductDetails() {
  const [product, setProduct] = useState({});
  // react-router-dom
  const { id } = useParams();
  useEffect(() => {
    (async function () {
      /***
       * fetch data from our API server
       *
       * ****/
      const response = await axios.get(URL_CONFIG.GET_PRODUCT_BY_ID + `/${id}`);

      const product = response.data.resource;
      const productMapped = {
        ...product,
        id: product["_id"],
        images: product.image,
        title: product.name || product.title,
      };
      setProduct(productMapped);
    })();
  }, []);

  if (Object.keys(product).length == 0) return <h3>Loading...</h3>;
  return (
    <>
      <h1>Products Page</h1>
      <div>
        <h2>{product.title}</h2>
        <p>Price: ${product.price}</p>
        <p>Description: {product.description}</p>
        <p>Category: {product.category}</p>
        <img src={product.image} alt={product.title} />
      </div>
    </>
  );
}

export default ProductDetails;
