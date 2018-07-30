# JSONParserForArduino
JSON Object Parser Not to Object Yes to String 

# Usage

1. `{"url": "gibHub.com"}` -> `findValueWithKey({"url": "gibHub.com"}, url)` retrun `"github.com"` 
  caution `"` is contained in returned Value.
  
2. `{"meta": ["s", "h", "i", "n"]}` -> `findValueWithKey({"meta": ["s", "h", "i", "n"]}, meta)` return `["s", "h", "i", "n"]`

3. `"github.com"` -> `removeDoublequotes("github.com")` return `github.com`

4. `["s", "h", "i", "n"]` -> `jsonArrayToCopy(DstArray, ["s", "h", "i", "n"])` return `DstArray = {"s","h","i","n"}`

# Caution
1. *Doublequotes*
