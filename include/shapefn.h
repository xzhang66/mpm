#ifndef MPM_SHAPEFN_H_
#define MPM_SHAPEFN_H_

#include <Eigen/Dense>

namespace mpm {

//! Base class of shape functions
//! \brief Base class that stores the information about shape functions
//! \tparam Tdim Dimension
template <unsigned Tdim>
class ShapeFn {
 public:
  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, Tdim, 1>;

  //! Constructor
  //! Assign variables to zero
  ShapeFn(){};

  //! Destructor
  virtual ~ShapeFn() {}

  //! Return number of functions
  virtual unsigned nfunctions() const = 0;

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  virtual Eigen::VectorXd shapefn(const VectorDim& xi) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  virtual Eigen::MatrixXd grad_shapefn(const VectorDim& xi) = 0;
};

}  // namespace mpm
#endif  // MPM_SHAPEFN_H_
