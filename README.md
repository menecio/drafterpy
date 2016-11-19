# DrafterPy
### API Blueprint Parser for Python
Python bindings for the [Drafter](https://github.com/apiaryio/drafter) library. It might also release the [Kraken](https://en.wikipedia.org/wiki/Kraken), so please be careful.

API Blueprint is Web API documentation language. You can find API Blueprint documentation on the [API Blueprint site](http://apiblueprint.org).

### Example

Simple api-blueprint to json parsing:

```python

        from drafterpy.blueprint import Blueprint

        content = "# My API\n" \
                  "## GET /message\n" \
                  "+ Response 200 (text/plain)\n" \
                  "\n" \
                  "        Hello World!\n"

        bp = Blueprint(content)
        bp.parse()
```

###Contribution
Any contributions and advices are welcome. Please report any issues at
the [Github Page](https://github.com/menecio/drafterpy)

## License
MIT License. See the [LICENSE](https://github.com/menecio/drafterpy/blob/master/LICENSE) file.
