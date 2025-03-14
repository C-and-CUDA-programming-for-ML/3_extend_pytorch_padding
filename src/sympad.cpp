#include <torch/extension.h>

#include <iostream>
using namespace torch::indexing;
using namespace std;

/**
 * Pads a 1-dimensional tensor symmetrically.
 * This is a helper function for _pad_symmetric.
 *
 * @param signal The input tensor to be padded.
 * @param padl The number of zeros to pad on the left side of the tensor.
 * @param padr The number of zeros to pad on the right side of the tensor.
 * @param dim The dimension along which to pad the tensor.
 * 
 * @return The padded tensor.
 */
torch::Tensor _pad_symmetric_1d(torch::Tensor signal, pair<int, int> pad_tuple, int dim)
{   int padl = pad_tuple.first;
    int padr = pad_tuple.second;
    int dimlen = signal.size(dim);
    // If the padding is greater than the dimension length,
    // pad recursively until we have enough values.
    if (padl > dimlen || padr > dimlen)
    {
        // make_pair allows you to call _pad_symmetric_1d.
        // https://en.cppreference.com/w/cpp/utility/pair/make_pair .

        if (padl > dimlen)
        {
            // TODO: pad as many values as possible and adjust padl.

        }
        else
        {
            // TODO: pad as many values as possible and adjust padr.
        }
        //TODO: Return i.e. with a call of _pad_symmetric_1d instead of signal.
        return signal;
    }
    else
    {
        vector<torch::Tensor> cat_list = {signal};
        // use i.e. the vectors insert and push_pack methods to implement symmetric padding.
        // torch tensors provide the slice( dimension, start, stop) function as well as
        // the flip(dimesnion) functions, which will help you. 

        // TODO: implement me.

        // return a tensor by calling torch::cat instead of signal
        return signal;
    }
}


/**
 * Pads a given signal symmetrically along multiple dimensions.
 *
 * @param signal The input signal to be padded.
 * @param pad_lists A vector of pairs representing the padding amounts for each dimension.
 *                  Each pair contains the left and right padding amounts for a dimension.
 * @return The padded signal.
 * @throws std::invalid_argument if the input signal has fewer dimensions than the specified padding dimensions.
 */
torch::Tensor pad_symmetric(torch::Tensor signal, vector<pair<int, int>> pad_lists)
{
    int pad_dims = pad_lists.size();
    if (signal.dim() < pad_dims)
    {
        throw std::invalid_argument("not enough dimensions to pad.");
    }

    int dims = signal.dim() - 1;
    //take a look at https://cplusplus.com/reference/algorithm/reverse/ .
    // loop through the dimension vector and pad the specified dimension using _pad_symmetric_1d.
    return signal;
}

// This code defines the python bindings for your function.
PYBIND11_MODULE(sympad, m) {
  m.def("pad_symmetric", &pad_symmetric, "A function that pads a tensor symmetrically");
  m.def("_pad_symmetric_1d", &_pad_symmetric_1d, "A function that pads a tensor symmetrically in 1D.");
}
