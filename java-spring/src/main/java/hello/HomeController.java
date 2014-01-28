package hello;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class HomeController {

	@RequestMapping(value="/", method=RequestMethod.GET)
    public String index(Model model) throws IOException {
		Map<String, String> data = getData();
		model.addAttribute(data);
		
        return "index";
    }

	private Map<String, String> getData() throws IOException {
		Map<String, String> data = new HashMap<String, String>();
		
		Document doc = Jsoup.connect("http://www.infoq.com/cn/news/190").get();
		for(Element e : doc.select("div.news_type_block")){
			Element link = e.select("h2 a").first();
			String url = link.attr("href");
			String title = link.text();
			data.put(url, title);
		}
		
		return data;
	}
}