DROP TABLE tweet_CLOB;
DROP TABLE tweet_binaryxml;
DROP TABLE film_binaryxml;

CREATE TABLE tweet_CLOB (xmlContent varchar(20), tweet CLOB);

CREATE TABLE tweet_binaryxml (xmlContent varchar(20), tweetXml XMLTYPE)
XMLTYPE COLUMN tweetXml STORE AS  BINARY XML;


CREATE TABLE film_binaryxml (xmlContent varchar(20), filmXml XMLTYPE)
XMLTYPE COLUMN filmXml STORE AS  BINARY XML;


INSERT INTO tweet_binaryxml (xmlContent,tweetXml)
VALUES ('tweet', sys.xmltype.createxml('
<tweets>
  <tweet id="t1" author="u1">
    <timestamp GMT="2"> 30 </timestamp>
    <message length="140" type="text" color="black" lang="en">
      <ref_user> example </ref_user>
      <text> absolutely smashed it at </text>
      <hashtags>
      	<ref_tag>mtvlivelockdown</ref_tag> 
      	<ref_tag>I&lt;3XML</ref_tag> 
      </hashtags>
      <text> ! Catch him at the official </text> 
      <ref_user> clubmtvuk </ref_user>
      <text> after party tonight @10 pm </text>
    </message>
    <responses>
        <response>yo !<date>12/01/18</date></response>
        <response>waw!<date>14/02/18</date></response>
        <response>lets go <date>16/04/18</date></response>
    </responses>  
    <gps>
      <latitude> 0 </latitude>
      <longitude> 0 </longitude>
      <altitude> 0 </altitude>
    </gps>
    <url_media>pic.com/TfXd2D3</url_media>
  </tweet>

  <tweet id="t2" author="u2">
    <timestamp GMT="2"> 31 </timestamp>
    <message length="140" type="text" color="black" lang="en">
      <ref_user> example </ref_user>
      <text> absolutely smashed it at </text>
      <hashtags>
      	<ref_tag>mtvlivelockdown</ref_tag> 
      	<ref_tag>efforts</ref_tag>
      </hashtags>
      <text> ! Catch him at the official </text> 
      <ref_user> clubmtvuk </ref_user>
      <text> after party tonight @10 pm </text>
    </message>
    <responses>
        <response>yo !<date>12/01/18</date></response>
        <response>waw!<date>14/02/18</date></response>
        <response>let s go <date>16/04/18</date></response>
    </responses> 
    <gps>
      <latitude> 0 </latitude>
      <longitude> 0 </longitude>
      <altitude> 0 </altitude>
    </gps>
    <url_media>pic.com/TfXd2D3</url_media>
  </tweet>

  <tweet id="t3" author="u2">
    <timestamp GMT="2"> 32 </timestamp>
    <message length="140" type="text" color="black" lang="en">
      <ref_user> example </ref_user>
      <text> absolutely smashed it at </text>
      <text> ! Catch him at the official </text> 
      <ref_user> clubmtvuk </ref_user>
      <text> after party tonight @10 pm </text>
    </message>
    <responses>
        <response>yo !<date>12/01/18</date></response>
        <response>waw!<date>14/02/18</date></response>
        <response>lets go <date>16/04/18</date></response>
    </responses>  
    <gps>
      <latitude> 0 </latitude>
      <longitude> 0 </longitude>
      <altitude> 0 </altitude>
    </gps>
    <url_media>pic.com/TfXd2D3</url_media>
  </tweet>

  <tweet id="t4" author="u3">
    <timestamp GMT="2"> 33 </timestamp>
    <message length="140" type="text" color="black" lang="en">
      <ref_user> example </ref_user>
      <text> absolutely smashed it at </text>
      <text> ! Catch him at the official </text> 
      <ref_user> clubmtvuk </ref_user>
      <text> after party tonight @10 pm </text>
    </message>
    <gps>
      <latitude> 0 </latitude>
      <longitude> 0 </longitude>
      <altitude> 0 </altitude>
    </gps>
    <url_media>pic.com/TfXd2D3</url_media>
  </tweet>

  <tweet id="t5" author="u3">
    <timestamp GMT="2"> 34</timestamp>
    <message length="140" type="text" color="black" lang="en">
      <ref_user> example </ref_user>
      <text> absolutely smashed it at </text>
      <text> ! Catch him at the official </text> 
      <ref_user> clubmtvuk </ref_user>
      <text> after party tonight @10 pm </text>
    </message>
    <gps>
      <latitude> 0 </latitude>
      <longitude> 0 </longitude>
      <altitude> 0 </altitude>
    </gps>
    <url_media>pic.com/TfXd2D3</url_media>
  </tweet>

  <user id="u1" OS="Windows">
    <name> MTV Music </name>
    <city> Montpellier </city>
    <country> France </country>
    <url_avatar> null </url_avatar>
    <follow_count> 24 </follow_count>
    <sub_count> 94728472 </sub_count>
    <description> MTV Music UK </description>
  </user>

  <user id="u2" OS="Windows">
    <name> NRJ Music </name>
    <city> Paris </city>
    <country> France </country>
    <url_avatar> null </url_avatar>
    <follow_count> 29 </follow_count>
    <sub_count> 1597383 </sub_count>
    <description> MTV Music UK </description>
  </user>

  <user id="u3" OS="Windows">
    <name> W9 Hits </name>
    <city> Berlin </city>
    <country> Germany </country>
    <url_avatar> null </url_avatar>
    <follow_count> 41 </follow_count>
    <sub_count> 12042 </sub_count>
    <description> MTV Music UK </description>
  </user>

</tweets>
  ') );

SELECT EXTRACT(tweetXml,'//tweet/@id') FROM tweet_binaryxml;
SELECT EXTRACT(tweetXml,'//tweet/message') FROM tweet_binaryxml;
SELECT EXTRACT(tweetXml,'//user/@id') FROM tweet_binaryxml;

tweet_binaryxml
SELECT XMLQUERY('for $x in //user  
  for $y in //tweet
    where $y/@author=$x/@id
      return 
      <result>
        <pair
          tweetID ="{$y/@id}"
          author="{$x/name/text()}"
          />
      </result>' 
  	PASSING tweetXml RETURNING CONTENT)
FROM tweet_binaryxml;

SELECT XMLQUERY('
	for $x in //tweet
	 	 return
	  if  ($x/responses) then
	  <retweet idtweet="{$x/@id}"><content>{$x/message}</content>
	    {$x/responses/response/date} 
	    </retweet>        
	    else
	    <nonRetwitted idtweet="{$x/@id}"/> ' 
    PASSING tweetXml RETURNING CONTENT)
FROM tweet_binaryxml;

SELECT XMLQUERY('
for $x in //user    
for $y in //tweet
    where $y/@author=$x/@id
      return 
      <result>
      <name>{$x/name/text()}</name>
      <dates>{$y/timestamp/text()}</dates>
      </result>' 
  	PASSING tweetXml RETURNING CONTENT)
FROM tweet_binaryxml;

