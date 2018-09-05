import numbers
from typing import List

import attr
from attr import attrib
from attr.validators import instance_of, optional


@attr.s
class BaseField:
    CAPTION: str = attrib(validator=instance_of(str))


@attr.s
class String(BaseField):
    value: str = attrib(validator=instance_of(str))


@attr.s
class Enum(BaseField):
    value: List[str] = attrib()
    initial: str = attrib(validator=optional(instance_of(str)), default=None)

    @value.validator
    def check(self, attr, values):
        if not isinstance(values, (list, set)):
            raise TypeError(f"{attr.name} must be a sequence type (list or set only), got a {type(values)}.")

        if not all(isinstance(value, str) for value in values):
            raise TypeError(f"{attr.name} must be a (list or tuple) of string.")

        if self.initial is not None:
            if self.initial not in values:
                raise TypeError(f"The initial condition must be within the declared values")


@attr.s
class DataReference(BaseField):
    value = attrib()

    @value.validator
    def check(self, attr, value):
        if not issubclass(value, AlfaSimType):
            raise TypeError(f"{attr.name} must be a valid AlfaSim type")


@attr.s
class Quantity(BaseField):
    value: numbers.Real = attrib(validator=instance_of(numbers.Real))
    unit: str = attrib(validator=instance_of(str))


@attr.s
class Table(BaseField):
    value: List[Quantity] = attrib()

    @value.validator
    def check(self, attr, values):
        if not isinstance(values, (list, set)):
            raise TypeError(f"{attr.name} must be a sequence type (list or set only), got a {type(values)}.")

        if not all(isinstance(value, Quantity) for value in values):
            raise TypeError(f"{attr.name} must be a (list or tuple) of Quantity.")


@attr.s
class Boolean(BaseField):
    value: bool = attrib(validator=instance_of(bool))


@attr.s
class AlfaSimType:
    name = attrib(default='alfasim')


@attr.s
class TracerType(AlfaSimType):
    type = attrib(default='tracer')
