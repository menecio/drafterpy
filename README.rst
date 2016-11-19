DrafterPy
=========

API Blueprint Parser for Python
-------------------------------
Python bindings for the `Drafter`_ library. It might also release the `Kraken`_, so please be careful.

API Blueprint is Web API documentation language. You can find API Blueprint documentation on the `API Blueprint site`_.

Example
-------

Simple api-blueprint to json parsing:

.. code:: python

        from drafterpy.blueprint import Blueprint

        content = "# My API\n" \
            "## GET /message\n" \
            "+ Response 200 (text/plain)\n" \
            "\n" \
            "        Hello World!\n"

        bp = Blueprint(content)
        bp.parse()


Contribution
------------
Any contributions and advices are welcome. Please report any issues at
the `Github Page`_.

License
-------
MIT License. See the `LICENSE`_ file.

.. _Drafter: https://github.com/apiaryio/drafter
.. _Kraken: https://en.wikipedia.org/wiki/Kraken 
.. _API Blueprint site: http://apiblueprint.org
.. _Github page: https://github.com/menecio/drafterpy
.. _LICENSE: https://github.com/menecio/drafterpy/blob/master/LICENSE
