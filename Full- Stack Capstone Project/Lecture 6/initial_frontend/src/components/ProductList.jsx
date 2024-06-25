import React from 'react';
import { Link } from 'react-router-dom';
function ProductList(props) {
    const { productList } = props;
    return (
        <>
            {productList == null ? <h3 > Loading...</h3> :
                productList.map((product) => {
                    return (<div className="product" key={product.id}>
                        <img src={product.image}
                            className='product_image' />
                        <div className="product_meta">
                            <p className="product_title">{product.title}</p>
                            <p className='Price'>$ {product.price}</p>

                        </div>
                        <Link to={`/product/${product.id}`}>Explore</Link>
                    </div>
                    )
                })}
        </>
    )
}

export default ProductList;