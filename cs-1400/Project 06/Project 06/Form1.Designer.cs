namespace Project_06
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.exitMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.methodLabel = new System.Windows.Forms.Label();
            this.cagegoryLabel = new System.Windows.Forms.Label();
            this.shippingSelect = new System.Windows.Forms.ComboBox();
            this.categorySelect = new System.Windows.Forms.ComboBox();
            this.countLabel = new System.Windows.Forms.Label();
            this.countBox = new System.Windows.Forms.TextBox();
            this.surchargeBox = new System.Windows.Forms.CheckBox();
            this.calculateButton = new System.Windows.Forms.Button();
            this.priceLabel = new System.Windows.Forms.Label();
            this.shippingPrice = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.surchargeLabel = new System.Windows.Forms.Label();
            this.menuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitMenuItem,
            this.aboutMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(455, 40);
            this.menuStrip.TabIndex = 0;
            this.menuStrip.Text = "menuStrip";
            // 
            // exitMenuItem
            // 
            this.exitMenuItem.Name = "exitMenuItem";
            this.exitMenuItem.Size = new System.Drawing.Size(64, 36);
            this.exitMenuItem.Text = "Exit";
            this.exitMenuItem.Click += new System.EventHandler(this.exitMenuItem_Click);
            // 
            // aboutMenuItem
            // 
            this.aboutMenuItem.Name = "aboutMenuItem";
            this.aboutMenuItem.Size = new System.Drawing.Size(92, 36);
            this.aboutMenuItem.Text = "About";
            this.aboutMenuItem.Click += new System.EventHandler(this.aboutMenuItem_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(86, 4);
            // 
            // methodLabel
            // 
            this.methodLabel.AutoSize = true;
            this.methodLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.methodLabel.Location = new System.Drawing.Point(12, 56);
            this.methodLabel.MaximumSize = new System.Drawing.Size(206, 0);
            this.methodLabel.MinimumSize = new System.Drawing.Size(206, 0);
            this.methodLabel.Name = "methodLabel";
            this.methodLabel.Size = new System.Drawing.Size(206, 25);
            this.methodLabel.TabIndex = 1;
            this.methodLabel.Text = "Shipping Method";
            // 
            // cagegoryLabel
            // 
            this.cagegoryLabel.AutoSize = true;
            this.cagegoryLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cagegoryLabel.Location = new System.Drawing.Point(229, 56);
            this.cagegoryLabel.Name = "cagegoryLabel";
            this.cagegoryLabel.Size = new System.Drawing.Size(206, 25);
            this.cagegoryLabel.TabIndex = 2;
            this.cagegoryLabel.Text = "Shipping Category";
            // 
            // shippingSelect
            // 
            this.shippingSelect.FormattingEnabled = true;
            this.shippingSelect.Location = new System.Drawing.Point(12, 84);
            this.shippingSelect.Name = "shippingSelect";
            this.shippingSelect.Size = new System.Drawing.Size(206, 33);
            this.shippingSelect.TabIndex = 3;
            // 
            // categorySelect
            // 
            this.categorySelect.FormattingEnabled = true;
            this.categorySelect.Items.AddRange(new object[] {
            "Per Item",
            "Per Pound"});
            this.categorySelect.Location = new System.Drawing.Point(229, 84);
            this.categorySelect.Name = "categorySelect";
            this.categorySelect.Size = new System.Drawing.Size(206, 33);
            this.categorySelect.TabIndex = 4;
            // 
            // countLabel
            // 
            this.countLabel.AutoSize = true;
            this.countLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.countLabel.Location = new System.Drawing.Point(12, 138);
            this.countLabel.MaximumSize = new System.Drawing.Size(206, 0);
            this.countLabel.MinimumSize = new System.Drawing.Size(206, 0);
            this.countLabel.Name = "countLabel";
            this.countLabel.Size = new System.Drawing.Size(206, 25);
            this.countLabel.TabIndex = 5;
            this.countLabel.Text = "Shipping Count";
            // 
            // countBox
            // 
            this.countBox.Location = new System.Drawing.Point(12, 166);
            this.countBox.MaximumSize = new System.Drawing.Size(206, 4);
            this.countBox.MinimumSize = new System.Drawing.Size(206, 4);
            this.countBox.Name = "countBox";
            this.countBox.Size = new System.Drawing.Size(206, 31);
            this.countBox.TabIndex = 6;
            // 
            // surchargeBox
            // 
            this.surchargeBox.AutoSize = true;
            this.surchargeBox.Location = new System.Drawing.Point(234, 168);
            this.surchargeBox.Name = "surchargeBox";
            this.surchargeBox.Size = new System.Drawing.Size(157, 29);
            this.surchargeBox.TabIndex = 7;
            this.surchargeBox.Text = "Is HI or AK?";
            this.surchargeBox.UseVisualStyleBackColor = true;
            // 
            // calculateButton
            // 
            this.calculateButton.Location = new System.Drawing.Point(12, 217);
            this.calculateButton.Name = "calculateButton";
            this.calculateButton.Size = new System.Drawing.Size(174, 41);
            this.calculateButton.TabIndex = 8;
            this.calculateButton.Text = "Calculate";
            this.calculateButton.UseVisualStyleBackColor = true;
            this.calculateButton.Click += new System.EventHandler(this.calculateButton_Click);
            // 
            // priceLabel
            // 
            this.priceLabel.AutoSize = true;
            this.priceLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.priceLabel.Location = new System.Drawing.Point(219, 225);
            this.priceLabel.Name = "priceLabel";
            this.priceLabel.Size = new System.Drawing.Size(165, 25);
            this.priceLabel.TabIndex = 9;
            this.priceLabel.Text = "Shipping Price";
            // 
            // shippingPrice
            // 
            this.shippingPrice.AutoSize = true;
            this.shippingPrice.Location = new System.Drawing.Point(219, 271);
            this.shippingPrice.Name = "shippingPrice";
            this.shippingPrice.Size = new System.Drawing.Size(54, 25);
            this.shippingPrice.TabIndex = 10;
            this.shippingPrice.Text = "$0.0";
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(12, 264);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(174, 39);
            this.clearButton.TabIndex = 11;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // surchargeLabel
            // 
            this.surchargeLabel.AutoSize = true;
            this.surchargeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.875F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.surchargeLabel.Location = new System.Drawing.Point(229, 140);
            this.surchargeLabel.MinimumSize = new System.Drawing.Size(206, 0);
            this.surchargeLabel.Name = "surchargeLabel";
            this.surchargeLabel.Size = new System.Drawing.Size(206, 25);
            this.surchargeLabel.TabIndex = 12;
            this.surchargeLabel.Text = "Surcharge";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(455, 319);
            this.Controls.Add(this.surchargeLabel);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.shippingPrice);
            this.Controls.Add(this.priceLabel);
            this.Controls.Add(this.calculateButton);
            this.Controls.Add(this.surchargeBox);
            this.Controls.Add(this.countBox);
            this.Controls.Add(this.countLabel);
            this.Controls.Add(this.categorySelect);
            this.Controls.Add(this.shippingSelect);
            this.Controls.Add(this.cagegoryLabel);
            this.Controls.Add(this.methodLabel);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "Form1";
            this.Text = "Project 6";
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem exitMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label methodLabel;
        private System.Windows.Forms.Label cagegoryLabel;
        private System.Windows.Forms.ComboBox shippingSelect;
        private System.Windows.Forms.ComboBox categorySelect;
        private System.Windows.Forms.Label countLabel;
        private System.Windows.Forms.TextBox countBox;
        private System.Windows.Forms.CheckBox surchargeBox;
        private System.Windows.Forms.Button calculateButton;
        private System.Windows.Forms.Label priceLabel;
        private System.Windows.Forms.Label shippingPrice;
        private System.Windows.Forms.Button clearButton;
        private System.Windows.Forms.Label surchargeLabel;
    }
}

