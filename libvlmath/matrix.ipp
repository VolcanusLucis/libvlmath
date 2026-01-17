#ifndef LIBVLMATH_MATRIX_IPP
#define LIBVLMATH_MATRIX_IPP

#include <memory>

namespace maths
{
    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix()
    {
        if constexpr (Rows != Columns) return;
        
        for (std::size_t x = 0; x < Rows || x < Columns; x++)
        {
            arr_[x][x] = 1;
        }
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix(const matrix& matrix)
    {
        for (std::size_t row = 0; row < Rows; row++)
        {
            for (std::size_t column = 0; column < Columns; column++)
            {
                arr_[row][column] = matrix[row][column];
            }
        }
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix(std::array<std::array<Type, Columns>, Rows> array)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] = array[x][y];
            }
        }
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix(const Type(&matrix)[Rows][Columns])
    {
        for (std::size_t row = 0; row < Rows; row++)
        {
            for (std::size_t column = 0; column < Columns; column++)
            {
                arr_[row][column] = matrix[row][column];
            }
        }
    }
    
    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    matrix<Type, Rows, Columns>::operator std::array<std::array<Type, Columns>, Rows>() const
    {
        return arr_;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr std::array<Type, Columns>& matrix<Type, Rows, Columns>::operator[](std::size_t index)
    {
        return arr_[index];
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr std::array<Type, Columns> matrix<Type, Rows, Columns>::operator[](std::size_t index) const
    {
        return arr_[index];
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator+(const matrix& other) const
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] + other[x][y];
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator-(const matrix& other) const
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] - other[x][y];
            }
        }
            
        return m;
    }
    
    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator*(const Type& scalar) const
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] * scalar;
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator/(const Type& scalar) const
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] / scalar;
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator+=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] += other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator-=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] -= other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator*=(const Type& scalar)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] *= scalar;
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator/=(const Type& scalar)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] /= scalar;
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr bool matrix<Type, Rows, Columns>::operator==(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                if (arr_[x][y] != other[x][y])
                    return false;
            }
        }
            
        return true;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr bool matrix<Type, Rows, Columns>::operator!=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                if (arr_[x][y] == other[x][y])
                    return true;
            }
        }
            
        return false;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr Type matrix<Type, Rows, Columns>::determinant() const
    {
        if constexpr (Rows != Columns)
        {
            return 0;
        }
        if constexpr (Rows == 2 && Columns == 2)
        {
            return arr_[0][0] * arr_[1][1] - arr_[1][0] * arr_[0][1];
        }
        
        // Laplace Expansion (modified to stop infinitely recurring templates)
        Type det = 0;
        for (std::size_t column = 0; column < Columns; column++)
        {
            std::array<std::array<Type, Columns - 1>, Rows - 1> minor = get_minor(0, column);
            
            Type minorDet = 0;
            if constexpr (Rows > 3 && Columns > 3)
            {
                minorDet = static_cast<matrix<Type, Rows - 1, Columns - 1>>(minor).determinant();
            }
            else
            {
                minorDet = minor[0][0] * minor[1][1] - minor[1][0] * minor[0][1];
            }
            
            int sign = column % 2 == 0 ? 1 : -1;
            det += sign * arr_[0][column] * minorDet;
        }
        
        return det;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::inverse() const
    {
        if constexpr (Rows != Columns)
        {
            return {};
        }
        
        Type det = determinant();
        if (det == 0)
        {
            return {};
        }
        
        //https://semath.info/src/inverse-cofactor-ex4.html
        Type inverse = static_cast<Type>(1.0) / det;
        if constexpr (Rows == 2 && Columns == 2)
        {
            return maths::matrix{{
                {arr_[1][1] * inverse, -arr_[0][1] * inverse},
                {-arr_[1][0] * inverse, arr_[0][0] * inverse}
            }};
        }
        
        // Suspiciously close to Determinant code - very boilerplate-y
        // TODO: Move Laplace expansion to own function
        matrix m = {};
        for (std::size_t row = 0; row < Rows; row++)
        {
            for (std::size_t column = 0; column < Columns; column++)
            {
                std::array<std::array<Type, Columns - 1>, Rows - 1> minor = get_minor(row, column);
                Type minorDet = 0;
                if constexpr (Rows > 3 && Columns > 3)
                {
                    minorDet = static_cast<matrix<Type, Rows - 1, Columns - 1>>(minor).determinant();
                }
                else
                {
                    minorDet = minor[0][0] * minor[1][1] - minor[1][0] * minor[0][1];
                }
                
                int sign = (row + column) % 2 == 0 ? 1 : -1;
                m[column][row] = minorDet * sign; // row-column assignment inversion
            }
        }
        
        
        return m * inverse;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr std::array<std::array<Type, Columns - 1>, Rows - 1> 
        matrix<Type, Rows, Columns>::get_minor(const std::size_t r, const std::size_t c) const
    {
        std::array<std::array<Type, Columns - 1>, Rows - 1> out;
        for (std::size_t row = 0; row < Rows - 1; row++)
        {
            for (std::size_t column = 0; column < Columns - 1; column++)
            {
                const bool offsetRow = row >= r;
                const bool offsetColumn = column >= c;
                out[row][column] = arr_[row + offsetRow][column + offsetColumn];
            }
        }
        
        return out;
    }
}

#endif
