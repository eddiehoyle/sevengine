#!/usr/bin/env python

"""
Generate C++ UV coords expressions for simpleFont.psd
"""

import string

GLYPH_WIDTH = 9
GLYPH_HEIGHT = 17

IMAGE_WIDTH = 300
IMAGE_HEIGHT = 300

LINE3 = "!\"#$%&'()*+,-./[\\]^^_{}~@:;<=>?"
LINE2 = "0123456789"
LINE1 = string.ascii_uppercase
LINE0 = string.ascii_lowercase

LINES = [
    LINE0,
    LINE1,
    LINE2,
    LINE3,
]

def get_coords():
    """Get the pixel coords of each registered character in the font map."""

    coords = []
    for line_index, line in enumerate(LINES):
        yA = line_index * GLYPH_HEIGHT
        yB = line_index * GLYPH_HEIGHT + GLYPH_HEIGHT
        for char_index, char in enumerate(line):
            xA = char_index * GLYPH_WIDTH
            xB = char_index * GLYPH_WIDTH + GLYPH_WIDTH
            data = {
                "char": char,
                "xA": xA,
                "xB": xB,
                "yA": yA,
                "yB": yB,
            }
            coords.append(data)
    return coords

def print_coords(coords):
    """Write UV coords for each character to stdout."""

    # C++ expression to be formatted
    expression = (
        "m_map.insert( std::pair< char, glm::vec4 >( "
        "'{char}', glm::vec4( {xA:0.4f}, {xB:0.4f}, {yA:0.4f}, {yB:0.4f} ) ) );"
    )

    for data in coords:

        # Normalize to image size
        normalized_x = normalize_coord(data["xA"], data["xB"])
        normalized_y = normalize_coord(data["yA"], data["yB"])

        # Update
        data.update({
            "xA": normalized_x[0],
            "xB": normalized_x[1],
            "yA": normalized_y[0],
            "yB": normalized_y[1],
        })

        # print
        print expression.format(**data)

def normalize_coord(a, b):
    """Normalize coords to UV space."""

    return map(lambda n: float(n)/IMAGE_WIDTH, [a, b])

def main():

    coords = get_coords();
    print_coords(coords)



if __name__ == '__main__':
    main()