import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import { Routes, Route, Navigate } from "react-router-dom";
import PageNotFound from './pages/PageNotFound'
import Home from './pages/Home';
import ProductDetails from './pages/ProductDetails';
import PaginationProvider from './contexts/PaginationContext';
function App() {
  return (
    <PaginationProvider>
      <Routes>
        <Route path="/" element={<Home></Home>}> </Route>
        <Route path="/product/:id" element={<ProductDetails></ProductDetails>}> </Route>
        <Route path="/home" element={<Navigate to="/"></Navigate>}></Route>
        <Route path="*" element={<PageNotFound></PageNotFound>}> </Route>
      </Routes>
    </PaginationProvider>
  )
}
export default App;