#ifndef LIBVLMATH_MATRIX_HPP
#define LIBVLMATH_MATRIX_HPP

#include <array>
#include <type_traits>

namespace maths
{
    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    class matrix
    {
    public:
        constexpr matrix();
        constexpr matrix(const matrix& matrix);
        explicit constexpr matrix(std::array<std::array<Type, Columns>, Rows> array);
        explicit constexpr matrix(const Type(&matrix)[Rows][Columns]);
        
        explicit operator std::array<std::array<Type, Columns>, Rows>() const;
        
        [[nodiscard]] constexpr std::array<Type, Columns>& operator[](std::size_t index);
        [[nodiscard]] constexpr std::array<Type, Columns> operator[](std::size_t index) const;
        
        [[nodiscard]] constexpr matrix operator+(const matrix& other) const;
        [[nodiscard]] constexpr matrix operator-(const matrix& other) const;
        [[nodiscard]] constexpr matrix operator*(const Type& scalar) const;
        [[nodiscard]] constexpr matrix operator/(const Type& scalar) const;
        
        [[nodiscard]] constexpr matrix& operator+=(const matrix& other);
        [[nodiscard]] constexpr matrix& operator-=(const matrix& other);
        [[nodiscard]] constexpr matrix& operator*=(const Type& scalar);
        [[nodiscard]] constexpr matrix& operator/=(const Type& scalar);
        
        [[nodiscard]] constexpr bool operator==(const matrix& other);
        [[nodiscard]] constexpr bool operator!=(const matrix& other);
        
        [[nodiscard]] constexpr matrix multiply() const;
        [[nodiscard]] constexpr matrix divide() const;
        
        [[nodiscard]] constexpr Type determinant() const;
        [[nodiscard]] constexpr matrix inverse() const;
    
    private:
        [[nodiscard]] constexpr std::array<std::array<Type, Columns - 1>, Rows - 1> 
                                get_minor(std::size_t r, std::size_t c) const;
        
        std::array<std::array<Type, Columns>, Rows> arr_ = {};
        static constexpr std::size_t rows_ = Rows;
        static constexpr std::size_t columns_ = Columns;
    };
}

#include <libvlmath/matrix.ipp>

#endif