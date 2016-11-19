from . import _drafter


SERIALIZE_FORMATS = ['json', 'yaml', ]


class Blueprint:
    """
    A class to declare parseable API-Blueprint objects.

    :param str content: string representation of blueprint content.
    """
    def __init__(self, content):
        self.content = content

    def parse(self, format='json'):
        """
        Will parse api-blueprint into a serialized format.
        :param str format: accepted values (json, yaml)
        """
        if format not in SERIALIZE_FORMATS:
            raise ValueError('Incorrect serialize format.')

        return _drafter.parse_blueprint_to(self.content, format)

    def is_valid(self):
        """
        Check if api-blueprint is well-formed.
        :returns bool: True if blueprint validates without errors and warnings.
        """
        return _drafter.check_blueprint(self.content)
