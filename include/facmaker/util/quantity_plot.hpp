#pragma once

#include <vector>

namespace fmk::util {

class QuantityPlot {
public:
    using ContainerT = std::vector<int>;

    QuantityPlot();
    QuantityPlot(std::size_t capacity);
    QuantityPlot(std::size_t capacity, int starting_val);

    /// Changes a value in the plot by a modifier.
    /// If the value already exists, the modifier is directly applied as `val += mod`. If
    /// the value doesn't exist, the plot will be extended until `tick` using the last value
    /// in it, and then the same `val += mod` change will be applied.
    void change_value(std::size_t tick, int modifier);

    /// Inserts values coming from the last available one until `tick`.
    void extrapolate_until(std::size_t tick);

    const ContainerT& container() const;

private:
    ContainerT _container;
};

} // namespace fmk::util