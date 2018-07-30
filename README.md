# JSONParserForArduino
JSON Object Parser Not to Object Yes to String 

# Usage

1. `{"url": "gibHub.com"}` findValueWithKey(String:url) retrun `"github.com"` 
  caution `"` is contained in returned Value.
  
2. `{"meta": ["s", "h", "i", "n"]}` findValueWithKey(String:meta) return `["s", "h", "i", "n"]`

3. `"github.com"`removeDoublequotes(String:"github.com") return `github.com`

# Caution
1. Doublequotes
