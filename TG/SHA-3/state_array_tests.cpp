// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "state_array.h"

using namespace std;

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "11001100110011001100110011001100110011001100110011";
const char *s3 = "10101010101010101010101010101010101010101010101010";
const char *s4 = "10011001100110011001100110011001100110011001100110";

using ST2 = StateArray<2>;
using BS50 = BitString<50>;

const char * state_array__in_and_out()
{
    ST2 a { BS50 { s1 } };
    mu_assert(a.s().to_string() == string(s1));
    return NULL;
}

const char * state_array__assignment()
{
    ST2 a { BS50 { s1 } };

    for (ST2::Coord3D write_coord = ST2::begin(); write_coord != ST2::end(); write_coord.next())
    {
        ST2::Coord3D read_coord = write_coord;
        read_coord.cycle();
        a.set(write_coord, a[read_coord]);
    }

    mu_assert(a.s().to_string() == string(s2));

    return NULL;
}

const char * state_array__xor()
{
    ST2 a { BS50 { s1 } };

    ST2::Coord3D a_coord = ST2::begin();
    ST2::Coord3D b_coord = ST2::begin();
    b_coord.next();

    while (a_coord != ST2::end() && b_coord != ST2::end())
    {
        a.XOR(a_coord, b_coord);
        a_coord.next();
        b_coord.next();
    }

    a_coord = ST2::end();
    a_coord.previous();
    a.XOR(a_coord, ST2::begin());

    mu_assert(a.s().to_string() == string(s3));

    return NULL;
}

const char * state_array__Coord2D_get()
{
    int count = 0;
    ST2 a { BS50 { s1 } };

    for (ST2::Coord2D coord = ST2::begin2D(); coord != ST2::end2D(); coord.next())
    {
        count++;

        mu_assert(a[coord].to_string() == string(coord.linear_index() % 2 == 0 ? "01" : "10"));
    }

    mu_assert(count == ST2::lane_count);

    return NULL;
}

const char * state_array__Coord2D_set()
{
    ST2 a { BS50 { s1 } };

    ST2::Coord2D a_coord = ST2::begin2D();
    ST2::Coord2D b_coord = ST2::begin2D();
    b_coord.next();

    while (a_coord != ST2::end2D() && b_coord != ST2::end2D())
    {
        const ST2::Lane temp = a[a_coord];
        a[a_coord] = a[b_coord];
        a[b_coord] = temp;
        a_coord.next();
        b_coord.next();
    }

    a_coord = ST2::end2D();
    a_coord.previous();
    a[a_coord] = a[ST2::begin2D()];

    mu_assert(a.to_string() == string(s4));

    return NULL;
}

const char * state_array__column_xor()
{
    ST2 a { BS50 { s1 } };

    string result;
    for (int column_index = 0; column_index < ST2::column_count; column_index++)
    {
        result += a.column_xor(column_index).to_string();
    }

    mu_assert(result == string("0110011001"));

    return NULL;
}

void all_tests()
{
    mu_test(state_array__in_and_out);
    mu_test(state_array__assignment);
    mu_test(state_array__xor);
    mu_test(state_array__Coord2D_get);
    mu_test(state_array__Coord2D_set);
    mu_test(state_array__column_xor);
}
