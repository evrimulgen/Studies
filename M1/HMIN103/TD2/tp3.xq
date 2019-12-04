for $x in //user  
  for $y in //tweet
    where $y/@author=$x/@id
      return 
      <result>
        <pair
          tweetID ="{$y/@id}"
          author="{$x/name/text()}"
          />
      </result>,

for $x in //user    
for $y in //tweet
    where $y/@author=$x/@id
      return 
      <result>
      <name>{$x/name/text()}</name>
      <dates>{$y/timestamp/text()}</dates>
      </result>,
            
 for $x in //tweet  
    where  count($x/text/text())= 2
     return $x/@id,
    
for $x in //tweet
  return
  if  ($x/responses) then
  <retweet idtweet="{$x/@id}"><content>{$x/message}</content>
    {$x/responses/response/date} 
    </retweet>        
    else
    <nonRetwitted idtweet="{$x/@id}"/> ,  

for $x in //user 
order by $x/name
return $x/name,

for $x in //tweet 
where $x/message/ref_tag/text()="I&lt;3XML"
return $x/@id,

    
let $list:=for $x in //tweet/timestamp/text()return $x
return (min($list),max($list))
