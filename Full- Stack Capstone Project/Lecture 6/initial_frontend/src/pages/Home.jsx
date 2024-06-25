import React, { useState, useEffect } from "react";
import ArrowCircleUpIcon from "@mui/icons-material/ArrowCircleUp";
import ArrowCircleDownIcon from "@mui/icons-material/ArrowCircleDown";
import KeyboardArrowLeftIcon from "@mui/icons-material/KeyboardArrowLeft";
import ChevronRightIcon from "@mui/icons-material/ChevronRight";
import ProductList from "../components/ProductList";
import basicOps from "../utility/basicOps";
import { usePaginationContext } from "../contexts/PaginationContext";
import axios from "axios";
import URL_CONFIG from "../constants/API_config";
function Home() {
  // preserver -> pagination
  /***single source of truth for all the products***/
  const [products, setProducts] = useState([]);
  /**********Action***********/
  /*********************** state ->term with which you want to filter the product list*****************************/
  const [searchTerm, setSearchTerm] = useState("");
  /**************************sort : 0 : unsorted , 1: incresing order , -1 : decreasing order ************************************/
  const [sortDir, setsortDir] = useState(0);

  // page num and page size
  const { pageSize, pageNum, setPageNum, setPageSize } = usePaginationContext();

  /****************get all the products*********************/
  useEffect(() => {
    (async function () {
      /***
       * fetch data from our API server
       *
       * ****/
      const response = await axios.get(URL_CONFIG.PRODUCTS_ROUTE);
      const productArr = response.data.ResourceList;
      const productMappedArr = productArr.map((product) => {
        return {
          ...product,
          id: product["_id"],
          images: product.image,
          title: product.name || product.title,
        };
      });
      setProducts(productMappedArr);
    })();
  }, []);

  const object = basicOps(products, searchTerm, sortDir, pageNum, pageSize);
  const filteredSortedpaginatedArr = object.filteredSortedpaginatedArr;
  const totalPages = object.totalPages;
  return (
    <>
      {/* header */}
      <header className="nav_wrapper">
        <div className="search_sortWrapper">
          <input
            className="search_input"
            type="text"
            value={searchTerm}
            onChange={(e) => {
              setSearchTerm(e.target.value);
              setPageNum(1);
            }}
          />
          <div className="icons_container">
            <ArrowCircleUpIcon
              style={{ color: "white" }}
              fontSize="large"
              onClick={() => {
                setsortDir(1);
                setPageNum(1);
              }}
            ></ArrowCircleUpIcon>
            <ArrowCircleDownIcon
              fontSize="large"
              style={{ color: "white" }}
              onClick={() => {
                setsortDir(-1);
                setPageNum(1);
              }}
            ></ArrowCircleDownIcon>
          </div>
        </div>
      </header>

      {/* main area  */}
      <main className="product_wrapper">
        {/* products will be there */}
        <ProductList productList={filteredSortedpaginatedArr}> ̰</ProductList>
      </main>
      {/* pagination */}
      <div className="pagination">
        <button
          onClick={() => {
            if (pageNum == 1) return;
            setPageNum((pageNum) => pageNum - 1);
          }}
          disabled={pageNum == 1 ? true : false}
        >
          <KeyboardArrowLeftIcon fontSize="large"></KeyboardArrowLeftIcon>
        </button>
        <div className="pagenum">{pageNum}</div>
        <button
          onClick={() => {
            if (pageNum == totalPages) return;
            setPageNum((pageNum) => pageNum + 1);
          }}
          disabled={pageNum == totalPages ? true : false}
        >
          <ChevronRightIcon fontSize="large"></ChevronRightIcon>
        </button>
      </div>
    </>
  );
}

export default Home;
