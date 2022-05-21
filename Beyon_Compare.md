# 脚本参考
> 脚本是一个简单的文本文件，其中包含可以控制程序并自动执行文件操作或生成报告的命令列表。

| 表示法 | 意义 | 
| :------: | :------: |  
|   \|   |   分隔可能的选项  |
|   ()  | 将所需表达式括起来|
|   []  |  将可选表达式括起  |
|   <>  | 将所需用户文本的说明括起来  |
| [...] | 跟在可以重复的表达式后面  |  

* 在任何命令中，您可以使用 `lt` 代替 `left` 或 `rt` 代替 `right`。  
* 这些命令的脚本命令(按字母顺序排列)：  
 `ATTRIB`  `BEEP`  `COLLAPSE`  `COMPARE`  `COPY`  `COPYTO`  `CRITERIA`  `DATA-REPORT`  `DELETE`  `EXPAND`  `FILE-REPORT`  `FILTER`  `FOLDER-REPORT`  `HEX-REPORT`  `LOAD`  `LOG`  `MOVE`  `MOVETO`  `MP3-REPORT`  `OPTION`  `PICTURE-REPORT`  `REGISTRY-REPORT`  `RENAME`  `SELECT`  `SNAPSHOT`  `SYNC`  `TEXT-REPORT`  `TOUCH`  `VERSION-REPORT` 
----------------------------------
### ATTRIB(文件的属性)  
* 用法:  
`attrib (+|-)<attribute set 1> [(+|-)<attribute set 2> [...]]`   
其中 `<attribute set> `是:  `[a][s][h][r]`  
Mac 和 Linux 版本不支持 `attrib`。  
在当前的选择中` 设置（+）` 或` 清除（-）` DOS文件属性。使用`a`为存档，`s`为系统，`h`为隐藏，`r`为只读。  

   变量 | 意义  
   -- | --  
   `a`|存档  
   `s`|系统
   `h`|隐藏
   `r`|只读  


* 示例：  
    `attrib +h`  
    `attrib +sh -a`
-------
### BEEP(蜂鸣)  
* 用法：  
    `beep`  
    蜂鸣计算机扬声器。无论`/silent`命令行开关如何设置，均会蜂鸣。
------
### COLLAPSE(折叠)  
* 用法：  
   `collapse  all`  
    `collapse <path 1> [<path 2> [...]]`  
    折叠所有文件夹或指定路径的文件夹。路径是相对基准文件夹而言，且不能包含通配符。
* 示例：  
  `collapse "My Folder 1" "My Folder 2"`
------
### COMPARE(比较)  
* 用法：  
  `compare [CRC|binary|rules-based]`  
   
  使用比较类型比较当前选择内容。默认使用最近一次的比较类型。   
  这个命令只比较文件一次。使用`CRITERIA`去改变比较修改后文件的方法。
  变量|意义
  :--|:--
  `CRC`|CRC
  `binary`|二进制
  `rules-based`|基于规则

-----
### COPY(复制)  
* 用法：  
    `copy (left->right|right->left) `  
    复制选定的文件/文件夹至指示的方向。
---
### COPYTO (复制到)  
* 用法：  
  `copyto [left|right|all] [path:(relative|base|none)] <path>`  
  使用`path:`选项，复制选定一侧指定的文件/文件夹至指定的路径。  
  变量|意义
  --|--
  `base`|保存完整文件夹结构相对所有选定项的基准文件夹。  
  `relative`|保持所有选定项最小的相对文件夹结构。  
>* 默认为`all` 和`path：none`。  
---
### CRITERIA (比较条件) 
* 用法：  
  `criteria [attrib:<attribute set>] [version] [timestamp[:[<number of seconds>sec][;IgnoreDST]]] [size|CRC|binary|rules-based] [timezone:(ignore|(left|right)(+|-)<0..12>)] [follow-symlinks] [ignore-unimportant]`  
其中`<attribute set>`是:
` [a][s][h][r] `  
Mac 和 Linux 版本不支持 `attrib`。  
选择所有comparison criteria的设置。  
>* `attrib`启动指定DOS文件的属性。使用`a`为存档，`s`为系统，`h`为隐藏，`r`为只读。  
>* `version`启用版本信息比较，用于exe可执行文件和dll动态链接库。  
>* `timestamp`启用时间戳比较。  
>>* `<number of seconds>sec` 将秒级在一定误差范围内时间视为匹配。
>>* `IgnoreDST` 将差别恰好为一个小时的时间视为匹配。
>* `size(大小)`、`CRC`、`binary(二进制)`和`rules-based(基于规则)`均为比较文件内容的方法。
>* `timezone`忽略时区差异或不在指定侧使用时区的时间偏移。
>* `follow-symlinks` 将符号链接和 NTFS 交汇点视为目标文件或文件夹，而不是链接本身。
>* `ignore-unimportant` 将不重要的差异视为匹配项。  
* 示例：  
  `criteria attrib:sh timestamp:2sec;IgnoreDST rules-based timezone:left+6`
---
### DATA-REPORT(数据报告)  
* 用法：  
  `data-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
  生成当前所选文件的数据比较报表。  
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`或者 `interleaved(交错)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为相同，且在所有布局中有效。
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。
>>* `line-numbers`在`side-by-side`布局中的行号。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。  
---
### DELETE(删除)  
* 用法：  
  `delete [recyclebin=(yes|no)] (left|right|all)`  
 在指定侧删除当前选定的文件/文件夹。`recyclebin(回收站)` 参数只有在`Windows`系统支持下有效。  
Windows不会将网络驱动器、FTP站点和压缩文档中的文件放入回收站。
---
### EXPAND(展开)  
* 用法：  
    `expand all`  
    `expand <path 1> [<path 2> [...]]`  
    展开指定的子文件夹或所有子文件夹。路径相对基准文件夹，且不包含通配符。子文件夹必须被展开以便使用其它命令，如 `SELECT`/`expand all`命令不会展开被文件过滤器排除的子文件夹。
----
### FILE-REPORT(文件报告)  
* 用法：  
  `file-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
  根据处理的文件类型生成当前所选文件的报告。例如，它将为与`Table Compare(表比较)`文件格式关联的文件类型生成 `DATA-REPORT`。 
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`或者 `interleaved(交错)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为相同，且在所有布局中有效。
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。
>>* `line-numbers`在`side-by-side`布局中的行号。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。 
* 示例：  
  `file-report layout:side-by-side options:display-mismatches &`  
`output-to:printer output-options:print-color,wrap-word`
-------
### FILTER(过滤器)  
* 用法：  
`filter <file masks>`  
`filter cutoff:([<|>](<timestamp>|<number of days>[days])|none)`  
`filter attrib:((+|-)<attribute set>|none)`  
`filter size:([<|>]<number>[KB|MB|GB|TB]|none)`  
`filter exclude-protected`  
`filter include-protected`  
其中 `<attribute set> `是:  `[a][s][h][r]`  
Mac 和 Linux 版本不支持 `attrib`、 `exclude-protected`、`include-protected`。  
通过使用名称筛选（`file masks文件掩码`）、日期筛选（`cutoff截止`）或其他筛选（`attrib属性`, `size大小`, `exclude-protected排除保护`或`include-protected包含保护`）来控制比较哪些文件夹和文件类型。  
>* 名称筛选器根据文件和文件夹的名称和路径包括和排除文件和文件夹。多个掩码可以用分号分隔。要指示掩码是排除掩码，请使用前导减号（-）。要指示掩码影响文件夹，请使用尾部反斜杠 （\）。  
>* `cutoff`排除所有相对当前系统时间的时间戳或天数（< days>days）早于 （<）或较新（>）的文件。默认使用截止：<。none用于移除日期过滤器。日期过滤是宽松的，如果希望得到正确的分析结果，则使用操作系统区域设置指定的格式。（参考 控制面板 > 区域和语言设置。） ）时间是可选的，且应该位于日期之后 （cutoff截止时间：“12/31/2012 12：00pm”）。如果表达式中包含空格,记住使用`引号（" "）`。  
>* `attrib`将比较某些文件具有包含DOS文件属性（+），且不具有排除属性（-）。使用`a`为存档，`s`为系统，`h`为隐藏，`r`为只读。`none`可被用于移除属性过滤器。  
>* `size`排除所有小于 （<）或大于（>）指定大小的文件。默认的单位为字节，但用户也可以指定其它单位如`KB`、 `MB`、 `GB`或`TB` 添加到末尾，以指示该值分别以千字节、兆字节、千兆字节或 TB 为单位。`none`可用于删除大小筛选。  
>* `exclude-protected`排除同时设置了系统和隐藏属性的文件和文件夹。  
>* `include-protected`包含同时设置了系统和隐藏属性的文件和文件夹。 
* 示例：  
   `filter "*.pas;*.dpr;*.dfm"`  
    `filter cutoff:<7days`  
    `filter cutoff:>"Dec 31, 2012"`  
    `filter cutoff:"12/31/2012 12:00pm"`  
    `filter attrib:-sh`  
    `filter "*.txt;-My Folder\" attrib:+r`  
----
### FOLDER-REPORT(文件夹报告)  
* 用法：  
    `folder-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>]`  
 生成当前加载的基文件夹的文件夹比较报告。文件夹以其当前状态显示。若要包括子文件夹，请在此前面添加一个“`expend all(全部展开)`”命令。
>* `layout` 控制报表的外观，可以是`side-by-side`, `summary` 或 `xml` 。
>* `options`是可选的。  
>>* 显示筛选器标志控制报表中包含的文件。可能的值为`display-all(全部显示)`, `display-mismatches(显示不匹配)`, `display-no-orphans(显示无孤立项)`, `display-mismatches-no-orphans(显示不匹配无孤立项)`, `display-orphans(显示孤立项)`, `display-left-newer(显示左新)`, `display-right-newer(显示右新)`, `display-left-newer-orphans(显示左-新-孤立项)`, `display-right-newer-orphans(显示右-新-孤立项)` and `display-matches(显示匹配项)`。默认情况下，使用`display-all(全部显示)`。  
>>* 通过使用标志 `column-version(列版本)`, `column-size(列大小)`, `column-crc(列 crc)`, `column-timestamp(列时间戳)`, `column-attributes(列属性)`, `column-group(列组)`, `column-owner(列所有者)` and `column-vcs(列 vcs)`，可以在报表中包含可选列（用逗号分隔）。默认情况下，包括`column-size(列大小)`和`column-timestamp(列时间戳)`。 `column-none(列 none)` 本身可用于清除缺省列。
>>* 使用包含`include-file-links`文件链接标志生成文件报告，并在文件夹报告中包括指向它们的链接。只有并排和 HTML 的文件夹报表才能使用此标志。
>*  `title`, `output-to` and `output-options`参数记录在“通用报告参数”下。

-----
### HEX-REPORT(十六进制报告)  
* 用法：  
  `hex-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
   生成当前所选文件的“十六进制"比较报表。  
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`或者 `interleaved(交错)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为相同，且在所有布局中有效。
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。  
>>* `line-numbers`在`side-by-side`布局中的行号。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。  
----
### LOAD(加载)  
* 用法：  
    `load <session>`  
    `load [create:(all|left|right)] <left path> [<right path>]`  
    加载指定的文件夹比较会话、指定的基文件夹或具有默认设置的新文件夹比较会话（`load <default>`）。未能加载基文件夹将导致脚本终止。

>* 加载会话会导致使用该会话的所有设置，但显示筛选器（显示全部、仅不匹配、仅匹配等）除外。
>* 加载基文件夹使用当前活动的设置。默认情况下，使用`program defaults`程序默认值。
>* 可选的 `create` 参数将创建一个基文件夹（如果该基文件夹尚不存在）。  
* 示例：  
    `load <default>`    
    `load "My Session"`   
    `load "C:\My Folder" "X:\Your Folder"`  
    `load <default>`
---
### LOG(日志)  
* 用法：  
  `log [none|normal|verbose] [[append:]<filename>]`  
  控制日志的详细程度和日志的存储位置。  
>* `none(无)`、`normal(正常)`和`verbose详细`决定了日志中使用的详细信息量。日志记录最初处于禁用状态，并在模式从`none` 更改为“无”时开始。
>* `append:`使日志记录添加到文件中，而不是替换它。默认情况下，日志输出为当前文件夹中的 Log.txt（例如，快捷方式属性中的 Windows“起始位置”文件夹）。
----
### MOVE(移动)  
* 用法：  
  `move (left->right|right->left)`  
  沿指定方向移动选定的文件/文件夹。
-----
### MOVETO(移动到)  
* 用法：  
  `moveto [left|right|all] [path:(relative|base|none)] <path>`  
  使用 `path:` 选项将指定侧的选定文件/文件夹移动到指定路径。
  变量|意义
  --|--
  `base`|保存完整文件夹结构相对所有选定项的基准文件夹。  
  `relative`|保持所有选定项最小的相对文件夹结构。  
>* 默认为`all` 和`path：none`。  
---
### MP3-REPORT(mp3报告)  
* 用法：  
  `mp3-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
  生成当前所选文件的 MP3 比较报告。
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为相同，且在所有布局中有效。
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。 
----
### OPTION (选项) 
* 用法：  
  `option stop-on-error`  
  `option confirm:(prompt|yes-to-all|no-to-all)`  
调整脚本处理选项。

>* `stop-on-error`使脚本监视各种错误情况，包括文件操作错误，并在发生错误时提示用户，然后再继续。  
>* `confirm`可以使用 `prompt`、`yes-to-all` 或 `no-to-all` 来处理由于文件操作而发生的确认对话框。默认情况下，使用`stop-on-error(提示符)`。
### PICTURE-REPORT(图片报告)  
* 用法：  
  `picture-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
  生成当前选定文件的图片比较报告。  
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为`summary(摘要)`布局中的匹配项。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。 
----
### REGISTRY-REPORT(注册表报告)  
* 用法：  
  `registry-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。  
------
### RENAME(重命名)  
* 用法：  
  `ename [regexpr <old mask>] <new mask>`  
使用指定的新掩码对当前所选`multi-file rename(内容执行多文件重命名)`。`regexpr` 使用旧掩码来执行正则表达式重命名。默认情况下，将执行 DOS 样式的重命名。
* 示例：  
  `rename *.bak`
  `rename regexpr (...)(...)\.txt $2$1.txt`
-----
### SELECT(选择)  
* 用法：  
  `select <selection mask 1> [<selection mask 2> [...]]`  
  其中`<selection mask(选择蒙版)>`是下列之一：
  `all`  
  `[(left|right|all).][(exact|diff|newer|older|orphan|all).][(files|folders|all)]`  
  `empty.folders`  
>* `left(向左)`、`right(向右)`或`all(全部)`将选择限制在指定的一侧。默认情况下，将使用`all(全部)`。
>* `exact(精确)`，`diff(差异)`，`newer(较新)`，`older(较旧)`，`orphan(孤立)`或`all(全部)`限制基于比较结果的选择。`diff`是指除时间戳以外的条件的差异。要比较时间戳，请改用`newer(较新)`或`older(较旧)`时间戳。文件夹必须仅包含要受影响的指定结果类型。默认情况下，将使用`all(全部)`。  
>* `files(文件)`, `folders(文件夹)` 或 `all(所有)`限制选择为文件，文件夹或两者。默认情况下,将使用`all(全部)`。
>* `empty.folders(空文件夹)`是一种特殊的选择掩码，它将选择空文件夹。
* 示例：  
`select all`  
`select left`  
`select exact`  
`select files`  
`select right.diff`  
`select left.folders`  
`select newer.files right.older.files`
-------
### SNAPSHOT(快照)  
* 用法：  
  `snapshot [save-crc] [save-version] [expand-archives] [follow-symlinks] [include-empty] [no-filters] left|right|path:<path> [output:<target>]`  
  保存指定文件夹的只读快照。
>* `save-crc` 计算所有文件的 CRC，并将其存储为快照的一部分。  
>* `save-version`存储可执行文件的版本信息。  
>* `expand-archives`以扩展格式存储存档文件的内容。  
>* `follow-symlinks`存储符号链接所指向的文件和文件夹。  
>* `include-empty`存储空文件夹或仅包含排除的文件。  
>* `no-filters`存储所有文件，而不考虑活动的文件名筛选器。  
>* `lift`、`right`和`path`指示存储哪个文件夹。`lift`或`right`将保存其中一个已加载基文件夹的快照，`path(路径)`将保存指定路径的快照.
>* `output(输出)`是可选的，用于确定快照的保存位置。默认情况下，它将保存在当前文件夹中. 
>>* 如果目标是完全限定的文件名，则该文件名将是快照的名称。如果目标没有扩展名，将使用 `.bcss`。  
>>* 如果目标未包含或引用文件夹，则会根据源文件夹的名称和当前系统日期生成文件名，例如`folder_2012-12-31.bcss`。如有必要，将在生成的名称中添加一个额外的数字，以防止其覆盖现有快照。  
* 示例：  
`snapshot save-crc save-version no-filters path:C:\ output:D:\`  
`snapshot left output:"My Snapshot.bcss"`
-----
### SYNC(同步)  
* 用法：  
  `sync [visible] [create-empty] (update|mirror):(left->right|right->left|all)`  
  通过复制和删除文件来同步文件夹。此命令不使用当前所选内容。
>* `visible` 启用“仅影响可见文件”行为。只有展开文件夹中的文件会受到影响。  
>* `create-empty`启用“创建空文件夹”行为。  
>* `update`将较新的文件和孤立文件复制到指示的方向，使对面的孤立文件和较新的文件保持不变。使用 `all`作为方向表示双向同步，并在两个方向上复制较新的文件和孤立文件。  
>* `mirror`使目标文件夹与源文件夹相同。较新、较旧、不同和孤立的文件都将复制到目标。目标中的孤立项将被删除。`all`方向在此上下文中不适用，并且无效。  
* 示例：  
  `sync create-empty mirror:left->right`
----
### TEXT-REPORT(文本报告)  
* 用法：  
  `text-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
>* `layout`控制报表的外观，可以是`side-by-side(并排)`, `summary(摘要)`, `interleaved(交错)`, `patch(修补)`, `statistics(统计信息)` 或 `xml`。已弃用的布局` over-under` 和 `composite` 已被`interleaved`所取代。  
>* `options(选项)`是可选的，并且对于每个布局使用不同。  
>>* `ignore-unimportant`将不重要文本中的差异视为匹配项，并在所有布局中都可用。  
>>* `display-all(显示全部)`、`display-mismatches(显示不匹配)`、`display-context(显示上下文)`或`display-matches(显示匹配)`可用于控制除`summary(摘要)`、`patch(补丁)`和`statistics(统计信息)`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all(全部显示)`。  
>>* `line-numbers(行号)`包括并排布局中的行号。  
>>* `strikeout-left-diffs(删除左差分)`在交错布局中划掉左差分线。  
>>* `strikeout-right-diffs(删除线右差分)`在交错布局中划掉右差分线。  
>>* `patch-normal(补丁正常)`, `patch-context(补丁上下文)` 或 `patch-unified(补丁统一)`格式在补丁布局中可用。默认情况下，使用`patch-normal(补丁正常)`。  
>* `title(标题)`、`output-to(输出到)`、`out-options(输出选项)`和`<comparison(比较)>`参数记录在“通用报告参数”下。  
>* 已弃用的`statistics(统计信息)`描述性选项将改为生成摘要报告，并向日志发布警告。已弃用的`stats-tabular统计信息表格`选项在`statistics(统计信息)`布局中被忽略：`statistics(统计信息)`布局现在始终为表格 （CSV）。  

* 示例：  
`text-report layout:interleaved options:display-context &`  
`output-to:printer output-options:print-color,wrap-word` 

  `text-report layout:patch options:patch-unified &`  
`output-to:"My Report.txt"`

----------
### TOUCH(触摸)  
* 用法：  
`touch (left->right|right->left)`  
`touch (left|right|all):(now|<timestamp>)`  
将时间戳从一端的文件复制到另一端的文件，或将指定端上所有文件的时间戳设置为当前系统时间（`now`）或指定的时间戳。您必须先选择文件，然后才能触摸它们。  
------
### VERSION-REPORT(版本报告)  
* 用法：  
  `version-report layout:<layout> [options:<options>] [title:<report title>] output-to:(printer|clipboard|<filename>) [output-options:<options>] [<comparison>]`  
  生成当前选定文件的版本比较报告。  
>* `layout`控制报表的外观，包括`side-by-side(并排)`、`summary(摘要)`。  
>* `options`为可选，对每个布局有不同用法。
>>* `ignore-unimportant`将不重要文本中的差异视为`summary(摘要)`布局中的匹配项。  
>>* `display-all`、`display-mismatches`或`display-matches`可用于控制除`summary`之外的所有布局中都包含哪些比较行。默认情况下，使用`display-all`。 
>* `title`、`output-to`、`output-options`和`<comparison>`参数的描述可在`Common Report Arguments(通用报告参数)`文档中找到。 
### Common report arguments(常见报告参数)  
报告命令必须包括有关报告应发送到何处的信息，并可能包括有关输出格式的其他信息。
参数|意义
:--|:--
data-report | 数据报告
file-report | 文件报告
folder-report | 文件夹报告
hex-report | 十六进制报告
mp3-report | MP3报告
picture-report | 图片报告
registry-report | 注册表报告
text-report | 文本报告
version-report | 版本报告

* `title`控制显示在报表顶部的标题。 

* `output-to`控制输出目标。它可以是`printer(打印机)`, `clipboard(剪贴板)`或`文件名`。

* `out-options`是可选的，对于每个输出目标，其用法不同。

    * `print-color(彩色打印)`或`print-mono(单色打印)`配色方案可用于`ptinter(打印机)`输出。默认情况下，使用`print-mono`。

    * `print-portrait(打印纵向)` 或 `print-landscape(横向打印)`可用于`ptinter(打印机)`输出。默认情况下，使用`print-portrait`。

    * `wrap-none(无换行)`, `wrap-character(自动换行)` 或 `wrap-word(自动换行)`控制是否换行 。`printer`输出可以使用所有三个选项。`HTML` 输出可以使用`wrap-none`和`wrap-character`。默认情况下，使用`wrap-none`。
    * `html-color`、`html-mono` 或 `html-custom`需要输出为 HTML 而不是纯文本。这些选项可用于`clipboard剪贴板`和`files文件`输出。`html-custom`需要外部样式表的文件名或 URL。

* <`comparison(比较)`>可以是会话名称或一对文件名。文件报告将使用指定的比较，而不是在脚本中选择的文件。使用保存的会话时，比较类型必须与报告类型匹配（例如，表比较会话必须使用`data-report`或`file-report`）。
* 示例：  
  `data-report layout:interleaved output-to:printer &`  
    `output-options:print-color,print-landscape`

  `file-report layout:summary output-to:clipboard &`  
   ` output-options:wrap-word,html-color`

  `text-report layout:patch options:patch-unified &`  
  `output-to:"My Report.txt"`



 



