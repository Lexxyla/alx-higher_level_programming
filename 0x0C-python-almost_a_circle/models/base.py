#!/usr/bin/python3

"""Defines a base class model"""


class Base:
    """Base Model
    This Represents the "Base" for all other class in the project
    Private Class Attributes:
        __nb_object (int): Number of instantiated Bases.
    """
    __nb_objects = 0

    def __init__(self, id=None):
        """ Initializes a new Base

        Args:
            id(int) : public instance attribute of the new Base
        """
        if id is not None:
            self.id = id
        else:
            Base.__nb_objects += 1
            self.id = Base.__nb_objects
